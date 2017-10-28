// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin Core developers
// Copyright (c) 2014-2017 The Dash Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"
#include "consensus/merkle.h"

#include "tinyformat.h"
#include "util.h"
#include "utilstrencodings.h"
#include "arith_uint256.h"
#include <assert.h>

#include <boost/assign/list_of.hpp>

#include "chainparamsseeds.h"

static CBlock CreateGenesisBlock(const char* pszTimestamp, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
	CMutableTransaction txNew;
	txNew.nVersion = 1;
	txNew.vin.resize(1);
	txNew.vout.resize(1);
	txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
	txNew.vout[0].nValue = genesisReward;
	txNew.vout[0].scriptPubKey = genesisOutputScript;

	CBlock genesis;
	genesis.nTime = nTime;
	genesis.nBits = nBits;
	genesis.nNonce = nNonce;
	genesis.nVersion = nVersion;
	genesis.vtx.push_back(txNew);
	genesis.hashPrevBlock.SetNull();
	genesis.hashMerkleRoot = BlockMerkleRoot(genesis);
	return genesis;
}

/**
* Build the genesis block. Note that the output of its generation
* transaction cannot be spent since it did not originally exist in the
* database.
*
* CBlock(hash=00000ffd590b14, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=e0028e, nTime=1390095618, nBits=1e0ffff0, nNonce=28917698, vtx=1)
*   CTransaction(hash=e0028e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
*     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d01044c5957697265642030392f4a616e2f3230313420546865204772616e64204578706572696d656e7420476f6573204c6976653a204f76657273746f636b2e636f6d204973204e6f7720416363657074696e6720426974636f696e73)
*     CTxOut(nValue=50.00000000, scriptPubKey=0xA9037BAC7050C479B121CF)
*   vMerkleTree: e0028e
*/
static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
	const char* pszTimestamp = "3DCoin first testnet chain test";
	const CScript genesisOutputScript = CScript() << ParseHex("") << OP_CHECKSIG;
	return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}

/**
* Main network
*/
/**
* What makes a good checkpoint block?
* + Is surrounded by blocks with reasonable timestamps
*   (no blocks before with a timestamp after, none after with
*    timestamp before)
* + Contains no strange transactions
*/


class CMainParams : public CChainParams {
public:
	CMainParams()
	{
		strNetworkID = "main";
		consensus.nSubsidyHalvingInterval = 103680; // Note: actual number of blocks per calendar year with DGW v3 is ~200700 (for example 449750 - 249050)
		consensus.nMasternodePaymentsStartBlock = 123780; // not true, but it's ok as long as it's less then nMasternodePaymentsIncreaseBlock
		consensus.nMasternodePaymentsIncreaseBlock = 157820; // actual historical value
		consensus.nMasternodePaymentsIncreasePeriod = 576 * 60; // 17280 - actual historical value
		consensus.nInstantSendKeepLock = 24;
		consensus.nBudgetPaymentsStartBlock = 125161; // actual historical value
		consensus.nBudgetPaymentsCycleBlocks = 16616; // ~(60*24*30)/2.6, actual number of blocks per month is 200700 / 12 = 16725
		consensus.nBudgetPaymentsWindowBlocks = 100;
		consensus.nBudgetProposalEstablishingTime = 60 * 60 * 24;
		consensus.nSuperblockStartBlock = 137440; // The block at which 12.1 goes live (end of final 12.0 budget cycle)
		consensus.nSuperblockCycle = 16616; // ~(60*24*30)/2.6, actual number of blocks per month is 200700 / 12 = 16725
		consensus.nGovernanceMinQuorum = 10;
		consensus.nGovernanceFilterElements = 20000;
		consensus.nMasternodeMinimumConfirmations = 15;
		consensus.nMajorityEnforceBlockUpgrade = 750;
		consensus.nMajorityRejectBlockOutdated = 950;
		consensus.nMajorityWindow = 1000;
		consensus.BIP34Height = 0;
		consensus.BIP34Hash = uint256S("0x");
		consensus.powLimit = uint256S("00000fffff000000000000000000000000000000000000000000000000000000");
		consensus.nPowTargetTimespan = 5 * 60; // 3DCoin: 5 minutes
		consensus.nPowTargetSpacing = 2.5 * 60; // 3DCoin: 2.5 minutes
		consensus.fPowAllowMinDifficultyBlocks = false;
		consensus.fPowNoRetargeting = false;
		consensus.nRuleChangeActivationThreshold = 1916; // 95% of 2016
		consensus.nMinerConfirmationWindow = 2016; // nPowTargetTimespan / nPowTargetSpacing
		consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
		consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 1199145601; // January 1, 2008
		consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 1230767999; // December 31, 2008

																					   // Deployment of BIP68, BIP112, and BIP113.
		consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;
		consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = 1486252800; // Feb 5th, 2017
		consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout = 1517788800; // Feb 5th, 2018

																				 /**
																				 * The message start string is designed to be unlikely to occur in normal data.
																				 * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
																				 * a large 32-bit integer with any alignment.
																				 */
		pchMessageStart[0] = 0xd1;
		pchMessageStart[1] = 0xd0;
		pchMessageStart[2] = 0xa2;
		pchMessageStart[3] = 0x7d;
		vAlertPubKey = ParseHex("0x");
		nDefaultPort = 15015;
		nMaxTipAge = 6 * 60 * 60; // ~144 blocks behind -> 2 x fork detection time, was 24 * 60 * 60 in bitcoin
		nPruneAfterHeight = 100000;

		genesis = CreateGenesisBlock(1503187200, 151965, 0x1e0ffff0, 1, 50 * COIN);
		consensus.hashGenesisBlock = genesis.GetHash();
		

		assert(consensus.hashGenesisBlock == uint256S("0x000006421e4f07d4d4ec8884ce41be66ccbb5bc423983859f10cadbc1346febb"));
		assert(genesis.hashMerkleRoot == uint256S("0x0f06ea982c10bfcbad17e6ad1b7e577c3ac069e281e24278f4118e75af3c85ee"));


		vSeeds.push_back(CDNSSeedData("3dcoin1", "seed1.3dcoin.io"));
		vSeeds.push_back(CDNSSeedData("3dcoin2", "seed2.3dcoin.io"));
		vSeeds.push_back(CDNSSeedData("3dcoin3", "seed3.3dcoin.io"));
		vSeeds.push_back(CDNSSeedData("3dcoin4", "seed4.3dcoin.io"));
		vSeeds.push_back(CDNSSeedData("Districts1", "seed1.districts.io"));
		vSeeds.push_back(CDNSSeedData("Districts2", "seed2.districts.io"));
		vSeeds.push_back(CDNSSeedData("Districts3", "seed3.districts.io"));
		vSeeds.push_back(CDNSSeedData("Districts4", "seed4.districts.io"));

		// 3DCoin addresses start with 'A'
		base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 23);
		// 3DCoin script addresses start with 'B'
		base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 26);
		// 3DCoin private keys start with 'P'
		base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 56);
		// 3DCoin BIP32 pubkeys start with 'xpub' (Bitcoin defaults)
		base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
		// 3DCoin BIP32 prvkeys start with 'xprv' (Bitcoin defaults)
		base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();
		// 3DCoin BIP44 coin type is '5'
		base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x05).convert_to_container<std::vector<unsigned char> >();

		vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_main, pnSeed6_main + ARRAYLEN(pnSeed6_main));

		fMiningRequiresPeers = true;
		fDefaultConsistencyChecks = false;
		fRequireStandard = true;
		fMineBlocksOnDemand = false;
		fTestnetToBeDeprecatedFieldRPC = false;

		nPoolMaxTransactions = 3;
		nFulfilledRequestExpireTime = 60 * 60; // fulfilled requests expire in 1 hour
		strSporkPubKey = "04549ac134f694c0243f503e8c8a9a986f5de6610049c40b07816809b0d1d06a21b07be27b9bb555931773f62ba6cf35a25fd52f694d4e1106ccd237a7bb899fdd";
		strMasternodePaymentsPubKey = "04549ac134f694c0243f503e8c8a9a986f5de6610049c40b07816809b0d1d06a21b07be27b9bb555931773f62ba6cf35a25fd52f694d4e1106ccd237a7bb899fdd";

		checkpointData = (CCheckpointData)
		{
			boost::assign::map_list_of
			(0, uint256S("0x000006421e4f07d4d4ec8884ce41be66ccbb5bc423983859f10cadbc1346febb"))
			(1, uint256S("0x000000cdbfc45b4fd1c20c0ae0455a1489ecf64d751ff2024e029f2f2d53622f")),

			
				1503187200, // * UNIX timestamp of last checkpoint block
				0,    // * total number of transactions between genesis and last checkpoint
							//   (the tx=... number in the SetBestChain debug.log lines)
				0        // * estimated number of transactions per day after checkpoint
		};
	}
};
static CMainParams mainParams;

/**
* Testnet (v3)
*/
class CTestNetParams : public CChainParams {
public:
	CTestNetParams()
	{
		strNetworkID = "test";
		consensus.nSubsidyHalvingInterval = 210240;
		consensus.nMasternodePaymentsStartBlock = 10000; // not true, but it's ok as long as it's less then nMasternodePaymentsIncreaseBlock
		consensus.nMasternodePaymentsIncreaseBlock = 46000;
		consensus.nMasternodePaymentsIncreasePeriod = 576;
		consensus.nInstantSendKeepLock = 6;
		consensus.nBudgetPaymentsStartBlock = 60000;
		consensus.nBudgetPaymentsCycleBlocks = 50;
		consensus.nBudgetPaymentsWindowBlocks = 10;
		consensus.nBudgetProposalEstablishingTime = 60 * 20;
		consensus.nSuperblockStartBlock = 61000; // NOTE: Should satisfy nSuperblockStartBlock > nBudgetPeymentsStartBlock
		consensus.nSuperblockCycle = 24; // Superblocks can be issued hourly on testnet
		consensus.nGovernanceMinQuorum = 1;
		consensus.nGovernanceFilterElements = 500;
		consensus.nMasternodeMinimumConfirmations = 1;
		consensus.nMajorityEnforceBlockUpgrade = 51;
		consensus.nMajorityRejectBlockOutdated = 75;
		consensus.nMajorityWindow = 100;
		consensus.BIP34Height = 21111;
		consensus.BIP34Hash = uint256S("0x0000000023b3a96d3484e5abb3755c413e7d41500f8e2a5c3f0dd01299cd8ef8");
		consensus.powLimit = uint256S("00000fffff000000000000000000000000000000000000000000000000000000");
		consensus.nPowTargetTimespan = 24 * 60 * 60; // 3DCoin: 1 day
		consensus.nPowTargetSpacing = 2.5 * 60; // 3DCoin: 2.5 minutes
		consensus.fPowAllowMinDifficultyBlocks = true;
		consensus.fPowNoRetargeting = false;
		consensus.nRuleChangeActivationThreshold = 1512; // 75% for testchains
		consensus.nMinerConfirmationWindow = 2016; // nPowTargetTimespan / nPowTargetSpacing
		consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
		consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 1199145601; // January 1, 2008
		consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 1230767999; // December 31, 2008

																					   // Deployment of BIP68, BIP112, and BIP113.
		consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;
		consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = 1456790400; // March 1st, 2016
		consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout = 1493596800; // May 1st, 2017

		pchMessageStart[0] = 0xde;
		pchMessageStart[1] = 0xb2;
		pchMessageStart[2] = 0xc4;
		pchMessageStart[3] = 0xcf;
		vAlertPubKey = ParseHex("0x");
		nDefaultPort = 16016;
		nMaxTipAge = 0x7fffffff; // allow mining on top of old blocks for testnet
		nPruneAfterHeight = 1000;

		genesis = CreateGenesisBlock(1503187200, 151965, 0x1e0ffff0, 1, 50 * COIN);
		consensus.hashGenesisBlock = genesis.GetHash();


		assert(consensus.hashGenesisBlock == uint256S("0x000006421e4f07d4d4ec8884ce41be66ccbb5bc423983859f10cadbc1346febb"));
		assert(genesis.hashMerkleRoot == uint256S("0x0f06ea982c10bfcbad17e6ad1b7e577c3ac069e281e24278f4118e75af3c85ee"));

		vFixedSeeds.clear();
		vSeeds.clear();
		vSeeds.push_back(CDNSSeedData("3dcoin1", "testseed1.3dcoin.io"));
		vSeeds.push_back(CDNSSeedData("Districts1", "testseed1.districts.io"));
		vSeeds.push_back(CDNSSeedData("3dcoin2", "testseed2.3dcoin.io"));
		vSeeds.push_back(CDNSSeedData("Districts2", "testseed2.districts.io"));

		// Testnet 3DCoin addresses start with 'T'
		base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 66);
		// Testnet 3DCoin script addresses start with 't'
		base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 128);
		// Testnet private keys start with '9' or 'c' (Bitcoin defaults)
		base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);
		// Testnet 3DCoin BIP32 pubkeys start with 'tpub' (Bitcoin defaults)
		base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
		// Testnet 3DCoin BIP32 prvkeys start with 'tprv' (Bitcoin defaults)
		base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();
		// Testnet 3DCoin BIP44 coin type is '1' (All coin's testnet default)
		base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

		vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_test, pnSeed6_test + ARRAYLEN(pnSeed6_test));

		fMiningRequiresPeers = true;
		fDefaultConsistencyChecks = false;
		fRequireStandard = false;
		fMineBlocksOnDemand = false;
		fTestnetToBeDeprecatedFieldRPC = true;

		nPoolMaxTransactions = 3;
		nFulfilledRequestExpireTime = 5 * 60; // fulfilled requests expire in 5 minutes
		strSporkPubKey = "0x";
		strMasternodePaymentsPubKey = "0x";

		checkpointData = (CCheckpointData)
		{
			boost::assign::map_list_of
			(0, uint256S("0x000006421e4f07d4d4ec8884ce41be66ccbb5bc423983859f10cadbc1346febb")),

				1503187200, // * UNIX timestamp of last checkpoint block
				0,     // * total number of transactions between genesis and last checkpoint
							//   (the tx=... number in the SetBestChain debug.log lines)
				0         // * estimated number of transactions per day after checkpoint
		};

	}
};
static CTestNetParams testNetParams;

/**
* Regression test
*/
class CRegTestParams : public CChainParams {
public:
	CRegTestParams()
	{
		strNetworkID = "regtest";
		consensus.nSubsidyHalvingInterval = 1000;
		consensus.nMasternodePaymentsStartBlock = 10;
		consensus.nMasternodePaymentsIncreaseBlock = 230;
		consensus.nMasternodePaymentsIncreasePeriod = 230;
		consensus.nInstantSendKeepLock = 6;
		consensus.nBudgetPaymentsStartBlock = 10;
		consensus.nBudgetPaymentsCycleBlocks = 50;
		consensus.nBudgetPaymentsWindowBlocks = 10;
		consensus.nBudgetProposalEstablishingTime = 60 * 20;
		consensus.nSuperblockStartBlock = 2500;
		consensus.nSuperblockCycle = 10;
		consensus.nGovernanceMinQuorum = 1;
		consensus.nGovernanceFilterElements = 100;
		consensus.nMasternodeMinimumConfirmations = 1;
		consensus.nMajorityEnforceBlockUpgrade = 750;
		consensus.nMajorityRejectBlockOutdated = 950;
		consensus.nMajorityWindow = 1000;
		consensus.BIP34Height = -1; // BIP34 has not necessarily activated on regtest
		consensus.BIP34Hash = uint256();
		consensus.powLimit = uint256S("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
		consensus.nPowTargetTimespan = 24 * 60 * 60; // 3DCoin: 1 day
		consensus.nPowTargetSpacing = 2.5 * 60; // 3DCoin: 2.5 minutes
		consensus.fPowAllowMinDifficultyBlocks = true;
		consensus.fPowNoRetargeting = true;
		consensus.nRuleChangeActivationThreshold = 108; // 75% for testchains
		consensus.nMinerConfirmationWindow = 144; // Faster than normal for regtest (144 instead of 2016)
		consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
		consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 0;
		consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 999999999999ULL;
		consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;
		consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = 0;
		consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout = 999999999999ULL;

		pchMessageStart[0] = 0xec;
		pchMessageStart[1] = 0xd1;
		pchMessageStart[2] = 0xc7;
		pchMessageStart[3] = 0xec;
		nMaxTipAge = 6 * 60 * 60; // ~144 blocks behind -> 2 x fork detection time, was 24 * 60 * 60 in bitcoin
		nDefaultPort = 17017;
		nPruneAfterHeight = 1000;

		genesis = CreateGenesisBlock(1503187200, 1, 0x207fffff, 1, 50 * COIN);
		consensus.hashGenesisBlock = genesis.GetHash();
		

		assert(consensus.hashGenesisBlock == uint256S("0x5e97796426c76bb2fcaf101c8a67fc000be374b13ac31032ba11e0c822782ce2"));
		assert(genesis.hashMerkleRoot == uint256S("0x0f06ea982c10bfcbad17e6ad1b7e577c3ac069e281e24278f4118e75af3c85ee"));

		vFixedSeeds.clear(); //! Regtest mode doesn't have any fixed seeds.
		vSeeds.clear();  //! Regtest mode doesn't have any DNS seeds.

		fMiningRequiresPeers = false;
		fDefaultConsistencyChecks = true;
		fRequireStandard = false;
		fMineBlocksOnDemand = true;
		fTestnetToBeDeprecatedFieldRPC = false;

		nFulfilledRequestExpireTime = 5 * 60; // fulfilled requests expire in 5 minutes

		checkpointData = (CCheckpointData)
		{
			boost::assign::map_list_of
			(0, uint256S("0x5e97796426c76bb2fcaf101c8a67fc000be374b13ac31032ba11e0c822782ce2")),
				0,
				0,
				0
		};
		// Regtest 3DCoin addresses start with 'R'
		base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 61);
		// Regtest 3DCoin script addresses start with 'r'
		base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 123);
		// Regtest private keys start with '9' or 'c' (Bitcoin defaults)
		base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);
		// Regtest 3DCoin BIP32 pubkeys start with 'tpub' (Bitcoin defaults)
		base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
		// Regtest 3DCoin BIP32 prvkeys start with 'tprv' (Bitcoin defaults)
		base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();
		// Regtest 3DCoin BIP44 coin type is '1' (All coin's testnet default)
		base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();
	}
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = 0;

const CChainParams &Params()
{
	assert(pCurrentParams);
	return *pCurrentParams;
}

CChainParams& Params(const std::string& chain)
{
	if (chain == CBaseChainParams::MAIN)
		return mainParams;
	else if (chain == CBaseChainParams::TESTNET)
		return testNetParams;
	else if (chain == CBaseChainParams::REGTEST)
		return regTestParams;
	else
		throw std::runtime_error(strprintf("%s: Unknown chain %s.", __func__, chain));
}

void SelectParams(const std::string& network)
{
	SelectBaseParams(network);
	pCurrentParams = &Params(network);
}
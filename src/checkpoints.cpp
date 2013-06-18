// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2013 GeoCoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        (     0, hashGenesisBlock)
        (         1, uint256("0xab0c5a482e7d49506e51738f6ba787ba67329a1d5cbb058e584ea3d680a1887b"))
        (         2, uint256("0x5863dfe7d4200f4df09471ec6e55e421abeef79668f8a050d11ef139c61c1b94"))
        (         3, uint256("0xeb25b41b236e060cef80c67ecc750f3a54d9e73561a9639e20211933f4f4c620"))
        (         4, uint256("0x176916f29b6f48c0cc38bc3b15b3d6a228154943a8e5f54199d3c10303c7542c"))
        (         5, uint256("0xcf2a7852a50109a0cf6a0d3a314025d40b1e4801c0ee5cd25ccf311badaade7e"))
        (         6, uint256("0xfef7687f485626c2ca7f934e4b3e8964a78c9ce5ac914892f8dbb5514f20a055"))
        (         7, uint256("0xa4288259f864120c59d8dab63428c73cb8102dd20209c9f6396369fa01102f1c"))
        (         8, uint256("0xdfe4fa220b15ecb4fad6b2c5f097ae20acd74493e8cb776154505dcb289954db"))
        (         9, uint256("0x4ea94da546dd4ea7b86750d28fa16af5942ab59330d11c7ee2b1800a65efa20a"))
        (        10, uint256("0x3d5cda2090d30af4c6ad3657ceb8b4828278adb890e29baf927d414a20dca45a"))
        (       100, uint256("0xc3f47587edca030801f7861657d5baef1b4ef60400a352faa2555e58c4e33c2c"))
        ;

    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;

        return mapCheckpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }
}

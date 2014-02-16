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
<<<<<<< HEAD
<<<<<<< HEAD
        ( 1, uint256("0xf6866df638f56aeefd90e14cc3d8a73ccb00f62f9314f80c0beef774a2499e78"))
        ( 5, uint256("0xbdac0ccbaf81e5baccf047015458a43d50c99469f48cf34e305594d459dcca90"))
        ( 10, uint256("0x58142805d8df0db328e6a888f9c431c0eb82c7bb9b28330a28b0b977d695049f"))
        ( 39, uint256("0x48b6b7a2e9139d4625113276226c14969a7ad8a287b9e15f78f71dc1be49b00a"))
        ( 8000, uint256("0x530f189f7b9a2848149c03e8e1689e59b4da81eb409b411092b3d12385232ddd"))
        (12000, uint256("0xa4461ea266967862a5e2dc1bfb57d550970156fa46cd1d19244902083c65b902"))
=======
>>>>>>> parent of a9894e5... GeoCoin 3.0
=======
>>>>>>> parent of a9894e5... GeoCoin 3.0
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

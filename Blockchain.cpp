#include "Blockchain.h"
#include "Block.h"

Blockchain::Blockchain()
{
    _vChain.emplace_back(Block(0, "Genesis Block"));
    _nDifficulty = 6;
}

Blockchain::~Blockchain()
{

}

void Blockchain::addBlock(Block bNew)
{
    bNew.sPrevHash = _getLastBlock().getHash();
    bNew.mineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

Block Blockchain::_getLastBlock() const 
{
    return _vChain.back();
}
#include "Block.hpp"

class LongBlock : public Block
{
    inline bool canMoveDown() override;
    bool canMoveDown(int x, int y) override;
    void printInNow(WINDOW *win) override;
    void printInBottom(WINDOW *win) override;
    bool canMoveRight() override;
    bool canMoveLeft() override;
    bool moveDown() override;
    bool moveRight() override;
    bool moveLeft() override;
    bool canMove(int x, int y, BlockDirection d) override;
    bool turnLeft() override;
    bool turnRight() override;
    //辅助函数用来实现turn的
    inline bool grandChildTurn(int to, int index, int ox, int oy, BlockDirection dir);
    inline bool childTurn(int to, int ox, int oy, BlockDirection dir);

public:
    ~LongBlock();
    LongBlock(Background &bg);
    void printBlock(WINDOW *win) override;
    BlockType getType() override;
    void stopMove() override;
    bool move(BlockDirection t) override;
    void moveToBottom() override;
    bool turn(BlockDirection t) override;
};

struct Queen {
    int x;
    int y;
};

bool hasHorizonalClash(const Queen& q1, const Queen& q2) {
    return q1.y == q2.y;
}

bool hasVerticalClash(const Queen& q1, const Queen& q2) { return q1.x == q2.x; }

bool hasDiagonalClash(const Queen& q1, const Queen& q2) {
    return (q1.x - q1.y) == (q1.x - q1.y) || (q1.x + q1.y) == (q1.x + q1.y);
}

int numberOfClashes(const Queen& q1, const Queen& q2) {
    int numberOfClashes = 0;
    if (hasHorizonalClash(q1, q2)) {
        numberOfClashes++;
    }
    if (hasVerticalClash(q1, q2)) {
        numberOfClashes++;
    }
    if (hasDiagonalClash(q1, q2)) {
        numberOfClashes++;
    }
    return numberOfClashes;
}

template <typename TBoard, int size = TBoard::size>
int cost(TBoard& board) {
    if (size < 2) return 0;
    int cost = 0;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            cost += numberOfClashes(board[i], board[j]);
        }
    }

    return cost;
}

template <typename TBoard,
          int sizeBoard = std::remove_reference_t<TBoard>::size>
bool hasQueen(TBoard&& board, int x, int y) {
    for (int i = 0; i < sizeBoard; ++i) {
        if (board[i].x == x && board[i].y == y) {
            return true;
        }
    }
    return false;
}

template <int sizeBoard>
class Board {
   private:
    Queen* queens;

   public:
    static constexpr int size = sizeBoard;

    template <typename... Queens>
    Board(Queens... qs) : queens{new Queen[]{qs...}} {
        static_assert(sizeof...(Queens) == sizeBoard,
                      "Invalid number of queens in constructor");
    }

    Queen operator[](int index) const { return queens[index]; }

    ~Board() {
        if (queens != nullptr) {
            delete queens;
        }
    }

    Board(Board&& b) : queens(b.queens) { b.queens = nullptr; }

    void setQueen(int queenIndex, int newX, int newY) {
        queens[queenIndex].x = newX;
        queens[queenIndex].y = newY;
    }
};

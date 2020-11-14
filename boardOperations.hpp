struct MoveOperation {
    int queenIndex;
    int x;
    int y;
    MoveOperation(const int queenIndex, const int x, const int y)
        : queenIndex(queenIndex), x(x), y(y) {}
};

std::string to_string(MoveOperation& m) {
    std::stringstream ss;
    ss << "move queen " << std::to_string(m.queenIndex)
       << " to x=" << std::to_string(m.x) << " y=" << std::to_string(m.y);
    return ss.str();
}

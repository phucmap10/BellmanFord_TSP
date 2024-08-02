#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <climits>
#include <cfloat>
#include <numeric>
#include <utility>
#include <bitset>
#include <tuple>
#include <functional>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int INF = 0x3f3f3f3f;

int vertexIndex(char vertex) {
    return vertex - 'A'; // return index of a char ( A -> 0)
}

char indexVertex(int index) {
    return 'A' + index; //return char of index ( 0 -> A)
}
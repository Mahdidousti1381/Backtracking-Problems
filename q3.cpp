
#include <iostream>
#include <vector>
#include <string>
//#include <ctime>
//#include <iomanip>
//#include <algorithm>
#include <cmath>

using namespace std;

void input_Taker(int const n, int const m, vector<vector<char>> &slots_matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> slots_matrix[i][j];
    }
}

void TakeLimitationInputs(int const n, int const m, vector<vector<int>> &col_matrix,
                          vector<vector<int>> &row_matrix) {
    int x_in_row;
    int x_in_col;
    int z_in_row;
    int z_in_col;
    for (int j = 0; j < m; j++) {
        cin >> x_in_col;
        col_matrix[0].push_back(x_in_col);
    }

    for (int l = 0; l < m; l++) {
        cin >> z_in_col;
        col_matrix[1].push_back(z_in_col);
    }

    for (int h = 0; h < n; h++) {
        cin >> x_in_row;
        row_matrix[0].push_back(x_in_row);
    }

    for (int k = 0; k < n; k++) {
        cin >> z_in_row;
        row_matrix[1].push_back(z_in_row);
    }
}

void slot_Maker(int const n, int const m, vector<vector<char>> const slots_matrix,
                vector<vector<int>> &slot_tags) {
    int tag = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (slots_matrix[i][j] == 'L' && slot_tags[i][j] == -2) {
                slot_tags[i][j] = tag;
                slot_tags[i][j + 1] = tag;
                tag++;
            }
            if (slots_matrix[i][j] == 'T' && slot_tags[i][j] == -2) {
                slot_tags[i][j] = tag;
                slot_tags[i + 1][j] = tag;
                tag++;
            }
            if (slots_matrix[i][j] == 'R' && slot_tags[i][j] == -2) {
                slot_tags[i][j] = tag;
                slot_tags[i][j - 1] = tag;
                tag++;
            }
            if (slots_matrix[i][j] == 'B' && slot_tags[i][j] == -2) {
                slot_tags[i][j] = tag;
                slot_tags[i - 1][j] = tag;
                tag++;
            }

        }
    }
}

void FindTagsPosition(const vector<vector<int>> &matrix, int value, vector<vector<int>> &tags_row,
                      vector<vector<int>> &tags_col) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == value) {
                tags_row[value].push_back(i);
                tags_col[value].push_back(j);
            }
        }
    }
}

void PrintOutput(vector<vector<string>> &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}

void MatrixValueChange(int const m, int const n, vector<vector<string>> &matrix, string new_value) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = new_value;
        }
    }
}

string PositionDetector(const vector<vector<string>> &matrix, int row, int col) {
    int n = matrix.size(); // number of rows
    int m = matrix[0].size(); // number of columns
    if (row == 0 && col == 0)
        return "top left corner";
    else if (row == 0 && col == m - 1)
        return "top right corner";
    else if (row == n - 1 && col == 0)
        return "bottom left corner";
    else if (row == n - 1 && col == m - 1)
        return "bottom right corner";
    else if (row == 0)
        return "top edge";
    else if (row == n - 1)
        return "bottom edge";
    else if (col == 0)
        return "left edge";
    else if (col == m - 1)
        return "right edge";
    else
        return "not on edge";
}

int positionCoder(const string &position) {
    if (position == "top left corner")
        return 1;
    else if (position == "top right corner")
        return 2;
    else if (position == "bottom left corner")
        return 3;
    else if (position == "bottom right corner")
        return 4;
    else if (position == "top edge")
        return 5;
    else if (position == "right edge")
        return 6;
    else if (position == "bottom edge")
        return 7;
    else if (position == "left edge")
        return 8;
    else
        return 9;
}

bool BlockPossibilityCheck(vector<vector<string>> &matrix, int row, int col, string creature) {
    string position = PositionDetector(matrix, row, col);
    int pos_code = positionCoder(position);

    switch (pos_code) {
        case (1):
            if (matrix[row][col + 1] == creature || matrix[row + 1][col] == creature)
                return false;
            else
                return true;
        case (2):
            if (matrix[row][col - 1] == creature || matrix[row + 1][col] == creature)
                return false;
            else
                return true;
        case (3):
            if (matrix[row][col + 1] == creature || matrix[row - 1][col] == creature)
                return false;
            else
                return true;
        case (4):
            if (matrix[row][col - 1] == creature || matrix[row - 1][col] == creature)
                return false;
            else
                return true;
        case (5):
            if (matrix[row][col + 1] == creature || matrix[row + 1][col] == creature ||
                matrix[row][col - 1] == creature)
                return false;
            else
                return true;
        case (6):
            if (matrix[row][col - 1] == creature || matrix[row + 1][col] == creature ||
                matrix[row - 1][col] == creature)
                return false;
            else
                return true;
        case (7):
            if (matrix[row][col + 1] == creature || matrix[row - 1][col] == creature ||
                matrix[row][col - 1] == creature)
                return false;
            else
                return true;
        case (8):
            if (matrix[row][col + 1] == creature || matrix[row + 1][col] == creature ||
                matrix[row - 1][col] == creature)
                return false;
            else
                return true;
        case (9):
            if (matrix[row][col + 1] == creature || matrix[row + 1][col] == creature ||
                matrix[row - 1][col] == creature || matrix[row][col - 1] == creature)
                return false;
            else
                return true;
    }
}

void count_creatures_in_row(string const creature, vector<vector<string>> matrix, vector<int> &creature_count_in_row) {
    int count = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == creature) {
                count++;
            }
        }
        creature_count_in_row.push_back(count);
        count = 0;
    }
}

void count_creatures_in_col(string const creature, vector<vector<string>> matrix, vector<int> &creature_count_in_col) {
    int count = 0;
    for (int i = 0; i < matrix[0].size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            if (matrix[j][i] == creature) {
                count++;
            }
        }
        creature_count_in_col.push_back(count);
        count = 0;
    }
}

bool check_creatures_count(vector<vector<string>> const &matrix, vector<vector<int>> const &col_limit,
        vector<vector<int>> const &row_limit) {
vector<int> x_count_in_col;
vector<int> x_count_in_row;
vector<int> z_count_in_col;
vector<int> z_count_in_row;
count_creatures_in_col("X", matrix, x_count_in_col);
count_creatures_in_col("Z", matrix, z_count_in_col);
count_creatures_in_row("X", matrix, x_count_in_row);
count_creatures_in_row("Z", matrix, z_count_in_row);

for (int col = 0; col < col_limit[0].size(); col++) {
if (x_count_in_col[col] != col_limit[0][col] && col_limit[0][col] != -1) {
return false;
}
if (z_count_in_col[col] != col_limit[1][col] && col_limit[1][col] != -1) {
return false;
}
}
for (int row = 0; row < row_limit[0].size(); row++) {
if (x_count_in_row[row] != row_limit[0][row] && row_limit[0][row] != -1) {
return false;
}
if (z_count_in_row[row] != row_limit[1][row] && row_limit[1][row] != -1) {
return false;
}
}
return true;
}

bool canFillBlock(const vector<vector<int>> &tags_col, vector<vector<int>> const &tags_row,
                  vector<vector<string>> next, int j, int condition) {
    switch (condition) {
        case (0):
            if (BlockPossibilityCheck(next, tags_row[j][0], tags_col[j][0], "X")
                && BlockPossibilityCheck(next, tags_row[j][1], tags_col[j][1], "Z")) {
                return true;
            } else
                return false;
        case (1):
            if (BlockPossibilityCheck(next, tags_row[j][0], tags_col[j][0], "Z")
                && BlockPossibilityCheck(next, tags_row[j][1], tags_col[j][1], "X")) {
                return true;
            } else
                return false;
        case (2):
            return true;
    }
}

void FillBlock(const vector<vector<int>> &tags_col, vector<vector<int>> const &tags_row,
               vector<vector<string>> &Result, int j, int condition) {
    if (condition == 0) {
        Result[tags_row[j][0]][tags_col[j][0]] = "X";
        Result[tags_row[j][1]][tags_col[j][1]] = "Z";
    } else if (condition == 1) {
        Result[tags_row[j][0]][tags_col[j][0]] = "Z";
        Result[tags_row[j][1]][tags_col[j][1]] = "X";
    } else if (condition == 2) {
        Result[tags_row[j][0]][tags_col[j][0]] = '-';
        Result[tags_row[j][1]][tags_col[j][1]] = '-';
    }
}

bool solve(int slots_count, const vector<vector<int>> &tags_col, vector<vector<int>> const &tags_row,
           vector<vector<string>> &result, int tag, const vector<vector<int>> &row_matrix,
           const vector<vector<int>> &col_matrix) {
    // cout << check_creatures_count(result, col_matrix, row_matrix);

    if ((tag == slots_count) && check_creatures_count(result, col_matrix, row_matrix)) {
        return true;
    }
    if ((tag == slots_count) && !check_creatures_count(result, col_matrix, row_matrix))
        return false;

    vector<vector<string>> temp = result;
    for (int condition = 0; condition < 3; condition++) {
        FillBlock(tags_col, tags_row, result, tag, condition);
        if (!canFillBlock(tags_col, tags_row, result, tag, condition)) {
            result = temp;
            continue;
        }
        if (solve(slots_count, tags_col, tags_row, result, tag + 1, row_matrix, col_matrix))
            return true;
        result = temp;
    }
    return false;
}

int main() {
    int n, m, No_Tag = -2;
    cin >> n >> m;
    int slots_count = m * n / 2;
    vector<vector<string>> answer(n, vector<string>(m));
    MatrixValueChange(m, n, answer, "0");
    vector<vector<int>> tags_col(m * n / 2);
    vector<vector<int>> tags_row(m * n / 2);
    vector<vector<int>> row_matrix(2);
    vector<vector<int>> col_matrix(2);
    vector<vector<char>> slots_matrix(n, vector<char>(m));
    vector<vector<int>> slot_tags(n, vector<int>(m, No_Tag));

    input_Taker(n, m, slots_matrix);
    TakeLimitationInputs(n, m, col_matrix, row_matrix);
    slot_Maker(n, m, slots_matrix, slot_tags);
    for (int label = 0; label < slots_count; label++) {
        FindTagsPosition(slot_tags, label, tags_row, tags_col);
    }
    if (solve(slots_count, tags_col, tags_row, answer, 0, row_matrix, col_matrix)) {
        PrintOutput(answer);
    } else {
        cout << "No Solution!" << endl;
    }
    return 0;
}



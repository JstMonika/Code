#include <bits/stdc++.h>
using namespace std;
#define MAX 214748

class Point
{
public:
    ~Point(){};
    Point(int row = 0, int col = 0)
    {
        this->row = row;
        this->col = col;
    }
    int getRow() { return row; };
    int getCol() { return col; };
    Point &operator=(const Point &other)
    {
        this->row = other.row;
        this->col = other.col;
        return *this;
    }
    bool operator==(const Point &other) const
    {
        return this->row == other.row && this->col == other.col;
    }
    bool operator!=(const Point &other) const
    {
        return !(*this == other);
    }
    void print_point() { cout << this->row << " " << this->col << endl; }
    bool too_far(const Point &other)
    {
        return (abs(this->row - other.row) + abs(this->col - other.col)) > 1;
    }
    bool notinmap(int map_row, int map_col) const
    {
        return this->row >= map_row || this->col == map_col || this->row < 0 || this->col < 0;
    }
    void visitthepoint(bool **visited)
    {
        visited[this->row][this->col] = true;
    }
    bool pointvisited(bool **visited) { return visited[this->row][this->col]; }
    bool vaild(char **map, int map_row, int map_col) const { return (!this->notinmap(map_row, map_col)) && (map[this->row][this->col] != '1'); }
    Point *uppoint() { return new Point(this->row - 1, this->col); }
    Point *dopoint() { return new Point(this->row + 1, this->col); }
    Point *lepoint() { return new Point(this->row, this->col - 1); }
    Point *ripoint() { return new Point(this->row, this->col + 1); }

private:
    int row;
    int col;
};

Point fp[MAX];

int main()
{
    int row, col, battery;
    cin >> row >> col >> battery;

    char **map = new char *[row];
    for (int i = 0; i < row; i++)
    {
        map[i] = new char[col];
        memset(map[i], '\0', col * sizeof(char));
    }

    int empty = 0, left_battery = battery;
    Point start;
    Point curpoint;
    queue<Point> qq;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            char tmp;
            cin >> tmp;
            if (tmp == '\n' || tmp == ' ')
                continue;
            map[i][j] = tmp;
            if (tmp == 'R')
            {
                start = Point(i, j);
                curpoint = start;
                empty++;
                qq.push(start);
            }
            else if (tmp == '0')
            {
                empty++;
                Point newpoint = Point(i, j);
                qq.push(newpoint);
                // qq.push(start);
            }
            else
            {
                continue;
            }
        }
    }
    qq.push(start);
    curpoint = start;
    int step = 0;

    // BFS
    while (qq.size() > 0)
    {
        bool **visited = new bool *[row];
        for (int i = 0; i < row; i++)
        {
            visited[i] = new bool[col];
            memset(visited[i], false, col * sizeof(bool));
        }
        queue<Point> qqmeow;
        qqmeow.push(curpoint);
        curpoint.visitthepoint(visited);
        while (qqmeow.size() > 0)
        {
            curpoint = qqmeow.front();
            // cout << "curpoint: ";
            // curpoint.print_point();
            qqmeow.pop();
            if (curpoint != fp[step - 1])
            {
                fp[step] = curpoint;
                step++;
                left_battery--;
            }
            if (left_battery <= battery / 2)
            {
                int i_fp = step - 2;
                if (i_fp > 0)
                    while (fp[i_fp] != start)
                    {
                        fp[step] = fp[i_fp];
                        i_fp--;
                        step++;
                        left_battery--;
                    }
                fp[step] = start;
                i_fp--;
                step++;
                curpoint = start;
                left_battery = battery;
            }
            if (curpoint.uppoint()->vaild(map, row, col) && !(curpoint.uppoint()->pointvisited(visited)))
            {
                qqmeow.push(*(curpoint.uppoint()));
                curpoint.uppoint()->visitthepoint(visited);
                // cout << "goup: ";
                // curpoint.uppoint()->print_point();
                curpoint = *(curpoint.uppoint());
            }
            else if (curpoint.dopoint()->vaild(map, row, col) && !(curpoint.dopoint()->pointvisited(visited)))
            {
                qqmeow.push(*(curpoint.dopoint()));
                curpoint.dopoint()->visitthepoint(visited);
                // cout << "godo: ";
                // curpoint.dopoint()->print_point();
                curpoint = *(curpoint.dopoint());
            }
            else if (curpoint.lepoint()->vaild(map, row, col) && !(curpoint.lepoint()->pointvisited(visited)))
            {
                qqmeow.push(*(curpoint.lepoint()));
                curpoint.lepoint()->visitthepoint(visited);
                // cout << "gole: ";
                // curpoint.lepoint()->print_point();
                curpoint = *(curpoint.lepoint());
            }
            else if (curpoint.ripoint()->vaild(map, row, col) && !(curpoint.ripoint()->pointvisited(visited)))
            {
                qqmeow.push(*(curpoint.ripoint()));
                curpoint.ripoint()->visitthepoint(visited);
                // cout << "gori: ";
                // curpoint.ripoint()->print_point();
                curpoint = *(curpoint.ripoint());
            }
            else
            {
                // cout << "the code is just like your life.\n";
                // cout << "No where to go. curpoint: ";
                // curpoint.print_point();
                // for (int i = 0; i < row; i++)
                // {
                //     visited[i] = new bool[col];
                //     memset(visited[i], false, col * sizeof(bool));
                // }
                // continue;
            }
            if (curpoint == qq.front())
            {
                qq.pop();
            }
        }
        for (int i = 0; i < row; i++)
        {
            delete visited[i];
        }
        delete visited;
    }

    cout << step << endl;
    for (int i = 0; i < step; i++)
    {
        fp[i].print_point();
        if (i > 0)
        {
            if (fp[i].too_far(fp[i - 1]))
            {
                cout << "too far at step: " << i << endl;
                fp[i - 1].print_point();
                fp[i].print_point();
                break;
            }
        }
    }

    if (fp[0] != fp[step - 1])
        cout << "didn't go back!\n";
}
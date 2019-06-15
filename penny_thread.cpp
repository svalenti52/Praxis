// penny_thread.cpp

#include <iostream>
#include <vector>
#include <unordered_set>
#include <chrono>
#include <future>
#include <sstream>

std::mutex mtx;

struct edge
{
    int x;
    int y;

    edge(int i_x, int i_y)
            :x(i_x), y(i_y) { }

    edge& operator=(const edge& rhs)
    {
        x = rhs.x;
        y = rhs.y;
    }
};

bool operator==(const edge& l, const edge& r)
{
    return l.x==r.x && l.y==r.y;
}

namespace std
{
    template<>
    struct hash<edge>
    {
        using argument_type = edge;
        using result_type = size_t;

        result_type operator()(const argument_type& c) const
        {
            return 10*static_cast<result_type>(c.x)
                    +static_cast<result_type>(c.y);
        }
    };
}

using namespace std;
using StateTuple = tuple<double, int, int, string, unordered_set<edge>>;

static atomic<int> counter = 0;

int GeneratePaths(vector<StateTuple>& q)
{
    atomic<int> nr_paths = 0;

    while (!q.empty())
    {
        auto[c, x, y, p, e] = q.back();
        q.pop_back();

        if (p.size()!=e.size() || (x<0 || x>4) || (y<0 || y>4))
            continue;

        ++nr_paths;
        ++counter;

        if (x==4 && y==4 && c<=50)
        {
            lock_guard<mutex> lg(mtx);
            cout << counter << ". " << p << "  cost = " << c << '\n';
            //++counter;
        }

        unordered_set<edge> E, W, N, S;
        for (auto curr_edges : e)
        {
            E.insert(curr_edges);
            W.insert(curr_edges);
            N.insert(curr_edges);
            S.insert(curr_edges);
        }
        E.insert(edge(2*x+1, 2*y));
        W.insert(edge(2*x-1, 2*y));
        N.insert(edge(2*x, 2*y-1));
        S.insert(edge(2*x, 2*y+1));

        q.emplace_back(StateTuple(c+2, x+1, y, p+'e', E));
        q.emplace_back(StateTuple(c-2, x-1, y, p+'w', W));
        q.emplace_back(StateTuple(c/2, x, y-1, p+'n', N));
        q.emplace_back(StateTuple(c*2, x, y+1, p+'s', S));
    }
    return nr_paths;
}

//-----------------------------------------------------------------------------

int MarkOutPath_1()
{
    vector<StateTuple> q;
    q.push_back(StateTuple(16.0, 4, 1, "eeees", {edge(1, 0), edge(3, 0), edge(5, 0), edge(7, 0), edge(8, 1)}));
    return GeneratePaths(q);
}

//-----------------------------------------------------------------------------

int MarkOutPath_21()
{
    vector<StateTuple> q;
    q.push_back(StateTuple(14.0, 4, 1, "eeese", {edge(1, 0), edge(3, 0), edge(5, 0), edge(6, 1), edge(7, 2)}));
    return GeneratePaths(q);
}

//-----------------------------------------------------------------------------

int MarkOutPath_22()
{
    vector<StateTuple> q;
    q.push_back(StateTuple(10.0, 2, 1, "eeesw", {edge(1, 0), edge(3, 0), edge(5, 0), edge(6, 1), edge(5, 2)}));
    return GeneratePaths(q);
}

//-----------------------------------------------------------------------------

int MarkOutPath_23()
{
    vector<StateTuple> q;
    q.push_back(StateTuple(24.0, 3, 2, "eeess", {edge(1, 0), edge(3, 0), edge(5, 0), edge(6, 1), edge(6, 3)}));
    return GeneratePaths(q);
}

//-----------------------------------------------------------------------------

int MarkOutPath_31()
{
    vector<StateTuple> q;
    q.push_back(StateTuple(5.0, 3, 0, "eesen", {edge(1, 0), edge(3, 0), edge(4, 1), edge(5, 2), edge(6, 1)}));
    return GeneratePaths(q);
}

//-----------------------------------------------------------------------------

int MarkOutPath_32()
{
    vector<StateTuple> q;
    q.push_back(StateTuple(12.0, 4, 1, "eesee", {edge(1, 0), edge(3, 0), edge(4, 1), edge(5, 2), edge(7, 2)}));
    return GeneratePaths(q);
}

//-----------------------------------------------------------------------------

int MarkOutPath_33()
{
    vector<StateTuple> q;
    q.push_back(StateTuple(20.0, 3, 2, "eeses", {edge(1, 0), edge(3, 0), edge(4, 1), edge(5, 2), edge(6, 3)}));
    return GeneratePaths(q);
}

//-----------------------------------------------------------------------------

int MarkOutPath_41()
{
    vector<StateTuple> q;
    q.push_back(StateTuple(32.0, 2, 3, "eesss", {edge(1, 0), edge(3, 0), edge(4, 1), edge(4, 3), edge(4, 5)}));
    return GeneratePaths(q);
}

//-----------------------------------------------------------------------------

int MarkOutPath_42()
{
    vector<StateTuple> q;
    q.push_back(StateTuple(14.0, 1, 2, "eessw", {edge(1, 0), edge(3, 0), edge(4, 1), edge(4, 3), edge(3, 4)}));
    return GeneratePaths(q);
}

//-----------------------------------------------------------------------------

int MarkOutPath_43()
{
    vector<StateTuple> q;
    q.push_back(StateTuple(18.0, 3, 2, "eesse", {edge(1, 0), edge(3, 0), edge(4, 1), edge(4, 3), edge(5, 4)}));
    return GeneratePaths(q);
}

//-----------------------------------------------------------------------------

int MarkOutPath_51()
{
    vector<StateTuple> q;
    q.push_back(StateTuple(4.0, 0, 1, "eesww", {edge(1, 0), edge(3, 0), edge(4, 1), edge(3, 2), edge(1, 2)}));
    return GeneratePaths(q);
}

//-----------------------------------------------------------------------------

int MarkOutPath_52() // q needs to be copied in
{
    vector<StateTuple> q;
    q.push_back(StateTuple(12.0, 1, 2, "eesws", {edge(1, 0), edge(3, 0), edge(4, 1), edge(3, 2), edge(2, 3)}));
    return GeneratePaths(q);
}

//-----------------------------------------------------------------------------

//	switch(i) 
//	{
//	case 1:
//		
//		break;
//	case 21:
//		//q.push_back(StateTuple(12.0, 3, 1, "eees", { edge(1,0), edge(3,0), edge(5,0), edge(6,1) }));
//		q.push_back(StateTuple(14.0, 4, 1, "eeese", { edge(1,0), edge(3,0), edge(5,0), edge(6,1), edge(7,2) }));
//		break;
//	case 22:
//		q.push_back(StateTuple(10.0, 2, 1, "eeesw", { edge(1,0), edge(3,0), edge(5,0), edge(6,1), edge(5,2) }));
//		break;
//	case 23:
//		q.push_back(StateTuple(24.0, 3, 2, "eeess", { edge(1,0), edge(3,0), edge(5,0), edge(6,1), edge(6,3) }));
//		break;
//	case 31:
//		//q.push_back(StateTuple(10.0, 3, 1, "eese", { edge(1,0), edge(3,0), edge(4,1), edge(5,2) }));
//		q.push_back(StateTuple(5.0, 3, 0, "eesen", { edge(1,0), edge(3,0), edge(4,1), edge(5,2), edge(6,1) }));
//		break;
//	case 32:
//		q.push_back(StateTuple(12.0, 4, 1, "eesee", { edge(1,0), edge(3,0), edge(4,1), edge(5,2), edge(7,2) }));
//		break;
//	case 33:
//		q.push_back(StateTuple(20.0, 3, 2, "eeses", { edge(1,0), edge(3,0), edge(4,1), edge(5,2), edge(6,3) }));
//		break;
//	case 41:
//		//q.push_back(StateTuple(16.0, 2, 2, "eess", { edge(1,0), edge(3,0), edge(4,1), edge(4,3) }));
//		q.push_back(StateTuple(32.0, 2, 3, "eesss", { edge(1,0), edge(3,0), edge(4,1), edge(4,3), edge(4,5) }));
//		break;
//	case 42:
//		q.push_back(StateTuple(14.0, 1, 2, "eessw", { edge(1,0), edge(3,0), edge(4,1), edge(4,3), edge(3,4) }));
//		break;
//	case 43:
//		q.push_back(StateTuple(18.0, 3, 2, "eesse", { edge(1,0), edge(3,0), edge(4,1), edge(4,3), edge(5,4) }));
//		break;
//	case 51:
//		//q.push_back(StateTuple(6.0, 1, 1, "eesw", { edge(1,0), edge(3,0), edge(4,1), edge(3,2) }));
//		q.push_back(StateTuple(4.0, 0, 1, "eesww", { edge(1,0), edge(3,0), edge(4,1), edge(3,2), edge(1,2) }));
//		break;
//	case 52:
//		q.push_back(StateTuple(12.0, 1, 2, "eesws", { edge(1,0), edge(3,0), edge(4,1), edge(3,2), edge(2,3) }));
//		break;
//	default:
//		return false;
//	}
//}

int main(int argc, char** argv)
{

    auto start = chrono::steady_clock::now();

    auto f1 = std::async(launch::deferred, MarkOutPath_1);
    auto f21 = std::async(launch::deferred, MarkOutPath_21);
    auto f22 = std::async(launch::deferred, MarkOutPath_22);
    auto f23 = std::async(launch::deferred, MarkOutPath_23);
    auto f31 = std::async(launch::deferred, MarkOutPath_31);
    auto f32 = std::async(launch::deferred, MarkOutPath_32);
    auto f33 = std::async(launch::deferred, MarkOutPath_33);
    auto f41 = std::async(launch::deferred, MarkOutPath_41);
    auto f42 = std::async(launch::deferred, MarkOutPath_42);
    auto f43 = std::async(launch::deferred, MarkOutPath_43);
    auto f51 = std::async(launch::deferred, MarkOutPath_51);
    auto f52 = std::async(launch::deferred, MarkOutPath_52);

    int tot_nr_paths = f1.get()+f21.get()+f22.get()+f23.get()+f31.get();
    tot_nr_paths += f32.get()+f33.get()+f41.get()+f42.get()+f43.get();
    tot_nr_paths += f51.get()+f52.get();

    auto end = chrono::steady_clock::now();

    auto proc_time = end-start;
    auto sec = chrono::duration_cast<chrono::seconds>(proc_time);

    cout << "\n\nTotal Number of Paths = " << tot_nr_paths << '\n';

    cout << "Processing Time = " << sec.count() << " seconds\n";
}

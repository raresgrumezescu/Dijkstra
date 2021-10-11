#include <bits/stdc++.h>
using namespace std;

#define NMAX 50005
#define INF (1 << 30)

class Task {
public:
    void solve() {
        read_input();
        print_output(get_result());
    }

private:
    	int n, m, k;
    	vector<pair<int, int>> adj[NMAX];
	int *sources;
    	void read_input() {
        cin >> n >> m >> k;
        for (int i = 1, x, y, w; i <= m; i++) {
            	cin >> x >> y >> w;
            	adj[x].push_back({y, w});
        }
        
        if (k > 0) {
        	sources = (int*) calloc(k + 1, sizeof(int));
        	for (int i = 1, dep ;i <= k; i++) {
        		cin >> dep;
        		sources[i] = dep;
        	}
        }
    	}

    	int get_result() {
        	vector<int> d(n + 1, 0);
		if (k > 0) {
			int minim = INF;
		
			int *depozit = (int*) calloc(n + 1, sizeof(int));
			for (int i = 1; i <= k; i++)
				depozit[sources[i]] = 1;
			for (int i = 1; i <= n; i++)
				if (depozit[i] == 1) {
					vector<int> d(n + 1, 0);
					dijkstra(i, d);
					for (int j = 1; j <= n; j++)
						if (depozit[j] == 0) {
							if (minim > d[j]) minim = d[j];
						}
				}
		
			if (minim == INF) return -1;
			return minim;
		}
		return -1;
    	}

 	   void dijkstra(int source, vector<int>& d) {
 	       fill(d.begin(), d.end(), INF); 
 	       set<pair<int, int>> pq;
 	       d[source] = 0;
 	       pq.insert({d[source], source});
	
	        while (!pq.empty()) {
	            auto top = pq.begin();
	            auto x = top->second;
	            pq.erase(top);
	
	            for (const auto& [y, w] : adj[x]) {
	                if (d[y] > d[x] + w) {
	                    pq.erase({d[y], y});
	                    d[y] = d[x] + w;
	                    pq.insert({d[y], y});
	                }
	            }
	        }
        
       	
	    }

   	 void print_output(int result) {
   	     cout << result;
   	     cout << "\n";
   	}
};

int main() {
	auto* task = new (nothrow) Task();
  	if (!task) {
        	cerr << "new failed: WTF are you doing? Throw your PC!\n";
        	return -1;
    	}
    	task->solve();
    	delete task;
    	return 0;
}

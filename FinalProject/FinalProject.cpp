/* "I pledge my honor that I have abided by the Stevens Honor System." 
Author: Nesar Ahmed
Date: 5/11/2016
*/

#include "Graph.h"
#include "Image.h"
#include "Path.h"
#include<stdlib.h>
int main() {
	Graph x;
	Image y(x.getNodes());
	y.draw(x.getArcs());
	y.print();
	string signal;
	do {
		cout << "enter either: Node name for its minimum spanning tree or " << endl;
		cout << "	       \"graph\" for original graph or" << endl;
		cout << "	       quit" << endl;
		cin >> signal;
		if (signal == "quit") break;

		else if (signal == "graph") {
			system("cls");
			y.print();
			continue;
		}
		else if (signal.size() >= 2) {
			cout << "invalid input" << endl;
			continue;
		}
		system("cls");
		compute(x, x.name2num(signal) - 1);
	} while (signal != "quit");
	return 0;
}
/*Write a program that can accomplish the following:

1. Read in a graph from graph.dat in the following format:

node# 1st-arc-to-node# weight-for-previous-arc 2nd-arc-to-node# weight-for-previous-arc 3rd-arc-to-node# weight-for-previous-arc ...
As an example:

1 2 10 3 5 4 100
2 1 5
4 3 50 2 10
In the above example, node 1 has an arc with weight 10 to node 2, weight 5 to node 3, and weight 100 to node 4. Node 2 has an arc with weight 5 to node 1. Node 4 has an arc to node 3 with weight 50 and to node 2 with weight 10.
Note that in the above example, there IS a node 3 despite not being specifically declared on a line. Any node that is either explicitly defined on its own line, or into which an arc goes, must be considered to exist.

2. Display an ascii art image of the graph on the screen. An sample for the above example is shown below. It is not the only possible example:

    +-----5-------->[3]
    |                ^
    |                |
    |                50
    |                |
+->[1]--10-->[2]<-10-+
|   |         |      |
+---=---5-----+      |
    |                |
   100               |
    |                |
    V                |
   [4]---------------+
As can be seen in the above example, use the following format:

nodes are written inside brackets
vertical lines are drawn with |
horizontal lines are drawn with -
90 degree bends, and intersections between lines (in order to share one line between two arcs) are drawn with +
a horizontal line crossing but not intersecting with a vertical line is drawn with an =
arc weights are written somewhere on the arc's line; if a line is shared between two arcs, only the part of the line used by only ONE arc may show the arc weight
to draw arrows, use <, >, V, and ^.
You do NOT need to optimize for the least number of crosses, turns, or intersections. You DO need to account for every possible graph where id(v) + od(v) <= 4 for all nodes v.

3. Display a chart, in an easily readable format, of the shortest path between each node s and every node t reachable from node s.

Remember: No late submissions. You may be able to resubmit (no guarantee) if you submit your assignment early and your assignment is graded with sufficient time for you to resubmit prior to the due date. There is no guarantee you will be able to resubmit, as it depends on grader time availability and when other students submit. The sooner you submit, the sooner you receive your final grade for the course and you are done for the semester! Also remember that this is an individual assignment.*/
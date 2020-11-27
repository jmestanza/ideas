# Python program for Dijkstra's single  
# source shortest path algorithm. The program is  
# for adjacency matrix representation of the graph 
  
# Library for INT_MAX 
import sys 
   
class Graph(): 
   
    def __init__(self, vertices): 
        self.V = vertices
        self.graph = {} 
        # self.graph = [[0 for column in range(vertices)]  
        #             for row in range(vertices)] 
   
    def printSolution(self, dist): 
        print ("Vertex tDistance from Source") 
        for node in range(self.V): 
            print (node, "t", dist[node]) 
   
    # A utility function to find the vertex with  
    # minimum distance value, from the set of vertices  
    # not yet included in shortest path tree 
    def minDistance(self, dist, sptSet): 
   
        # Initilaize minimum distance for next node 
        min = sys.maxsize 
   
        # Search not nearest vertex not in the  
        # shortest path tree 
        for v in range(self.V): 
            if dist[v] < min and sptSet[v] == False: 
                min = dist[v] 
                min_index = v 
   
        return min_index 
   
    # Funtion that implements Dijkstra's single source  
    # shortest path algorithm for a graph represented  
    # using adjacency matrix representation 
    def dijkstra(self, src): 
   
        dist = [sys.maxsize] * self.V 
        dist[src] = 0
        sptSet = [False] * self.V 
   
        for cout in range(self.V): 
   
            # Pick the minimum distance vertex from  
            # the set of vertices not yet processed.  
            # u is always equal to src in first iteration 
            u = self.minDistance(dist, sptSet) 
   
            # Put the minimum distance vertex in the  
            # shotest path tree 
            sptSet[u] = True
   
            # Update dist value of the adjacent vertices  
            # of the picked vertex only if the current  
            # distance is greater than new distance and 
            # the vertex in not in the shotest path tree 
            for v in range(self.V):
                if not u in graph:
                    pass
                else:
                    if not v in graph[u]:
                        pass
                    else:
                        if self.graph[u][v] > 0 and sptSet[v] == False and dist[v] > dist[u] + self.graph[u][v]: 
                            dist[v] = dist[u] + self.graph[u][v] 
        
        self.printSolution(dist) 
   
# Driver program 
people,encounters = [int(el) for el in input().split(" ")]
g = Graph(people) 
graph = {}
prob_graph = {}

for i in range(encounters):
    [u,v] = [int(el) for el in input().split(" ")]
    if not (u-1) in graph:
        graph[u-1] = []
        graph[u-1].append(v-1)
    else:     
        graph[u-1].append(v-1)

    if not (v-1) in graph:
        graph[v-1] = []
        graph[v-1].append(u-1)
    else:     
        graph[v-1].append(u-1)

print(graph)
g.graph = graph   
g.dijkstra(0); 
  
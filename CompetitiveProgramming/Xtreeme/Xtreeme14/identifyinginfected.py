

def traverse(curr,end,cnt):
    if curr==end or visited[u]:
        return
    visited[curr] = 1
    
    if not visited[curr]:
        if len(graph[curr])>1:
            return cnt
        else:
            traverse(graph[curr][0],end,cnt+1)

people,encounters = [int(el) for el in input().split(" ")]

graph = {}
prob_graph = {}

freq = [0]*(people+1)
visited = [0]*(people+1)


for i in range(encounters):
    [u,v] = [int(el) for el in input().split(" ")]
    if not (u) in graph:
        graph[u] = []
        graph[u].append(v)
        prob_graph[u] = [0.0]
    else:     
        graph[u].append(v)

    if not (v) in graph:
        graph[v] = []
        graph[v].append(u)
        prob_graph[v] = [0.0]
    else:     
        graph[v].append(u)

    freq[u] +=1
    freq[v] +=1
print(freq)
print(graph)

queries = int(input())
for q in range(queries):
    [u,v] = [int(el) for el in input().split(" ")]
    # curr = u

traverse(u,v)
print(prob_graph)




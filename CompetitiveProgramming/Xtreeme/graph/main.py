def traverse(graph, src, dst, node_not_available):
    if src == dst:
        return True

    if src in visited:
        return False
    else:
        visited[src] = True

    if src == node_not_available:
        return False

    neighbours = [neighbour for [neighbour, distance] in graph[src]]
    for neighbour in neighbours:
        if traverse(graph, neighbour, dst, node_not_available):
            return True

    return False


def get_visitable_neighbours(adj_list, baddest_node):
    ans = []
    for [neigh, weight] in adj_list:
        if neigh not in visited and neigh != baddest_node:
            ans.append([neigh, weight])
    return ans


[N, M, src, dst] = [int(el) for el in input().split(" ")]

graph = {}
for m in range(M):
    [a, b, d] = [int(el) for el in input().split(" ")]
    if not a in graph:
        graph[a] = []
    if not b in graph:
        graph[b] = []

    graph[b].append([a, d])
    graph[a].append([b, d])

possible_deleted_nodes = []

visited = {}
for node_to_delete in range(1, N + 1):
    if node_to_delete != src and node_to_delete != dst:
        # print(f'deleting node... {node_to_delete}')
        visited = {}
        if traverse(graph, src, dst, node_to_delete):
            # print(f'could traverse in spite of deleting node {node_to_delete}')
            possible_deleted_nodes.append(node_to_delete)

# print(possible_deleted_nodes)
# now we have the nodes we want to delete

# make a distinct graph for each option , or give it a super weight


visited = {}

def shortestPath(source, final_node, bad_node):
    max_value = float('inf')
    dist = [max_value] * (N + 1)  # ignore node 0
    curr_node = src
    dist[curr_node] = 0
    Q = [[source, 0]]
    while len(Q) > 0:
        [curr_node, curr_distance] = Q.pop(0)
        visitable_neighbours = get_visitable_neighbours(graph[curr_node], bad_node)
        for [neighbour, distance] in visitable_neighbours:
            dist[neighbour] = min(dist[curr_node] + distance, dist[neighbour])
            Q += get_visitable_neighbours(graph[curr_node], bad_node)
            # print(dist)
        for [neighbour, distance] in visitable_neighbours:
            visited[neighbour] = True
    return dist[final_node]


# print(shortestPath(src, dst, 3))
max_path = float('-inf')
max_index = -1
for i, evil_node in enumerate(possible_deleted_nodes):
    visited = {}
    path = shortestPath(src, dst, evil_node)
    # print("PATH=", path)
    if path > max_path:
        max_path = path
        max_index = i

print(possible_deleted_nodes[max_index])
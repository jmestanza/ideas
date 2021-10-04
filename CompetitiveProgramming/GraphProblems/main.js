const graph = {
    a: ['b'],
    b: ['c', 'd', 'e'],
    c: [],
    d: [],
    e: ['f', 'g'],
    f: [],
    g: []
};

const dfsPrint = (graph, node) => {
    console.log(node);
    for(let neighbour of graph[node]){
        dfsPrint(graph, neighbour);
    }
}

dfsPrint(graph, 'a');


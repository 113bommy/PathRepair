import sys as _sys


ALICE = "Alice"
BOB = "Bob"

MAX_GRAPH_SIZE = 10 ** 5


def main():
    t = int(input())
    for i in range(t):
        n, a, b, da, db = _read_ints()
        a -= 1
        b -= 1
        graph = [set() for v in range(n)]
        for i in range(n-1):
            u, v = _read_ints()
            u -= 1
            v -= 1
            graph[u].add(v)
            graph[v].add(u)
        winner = who_wins(
            graph=graph,
            alice_start_vertex=a,
            alice_speed=da,
            bob_start_vertex=b,
            bob_speed=db
        )
        print(winner)


def _read_line():
    return _sys.stdin.readline()


def _read_ints():
    return map(int, _read_line().split(" "))


def who_wins(*, graph, alice_start_vertex, bob_start_vertex, alice_speed, bob_speed):
    assert len(graph) <= MAX_GRAPH_SIZE
    distance = find_distance(alice_start_vertex, bob_start_vertex, graph)
    v_1 = find_farthest_vertices(0, graph)[0].pop()
    max_vertices_distance = find_farthest_vertices(v_1, graph)[1]
    if alice_speed >= distance:
        winner = ALICE
    elif 2 * alice_speed + 1 >= max_vertices_distance:
        winner = ALICE
    elif bob_speed >= 2 * alice_speed + 1:
        winner = BOB
    else:
        winner = ALICE
    return winner


def find_distance(vertex_1, vertex_2, graph):
    passed = {vertex_1}
    distance = 0
    candidates = graph[vertex_1]
    while vertex_2 not in passed:
        new_candidates = set()
        for candidate in candidates:
            passed.add(candidate)
            new_candidates |= graph[candidate] - passed
        candidates = new_candidates
        distance += 1
    return distance


def find_farthest_vertices(vertex, graph):
    passed = {vertex}
    distance = 0
    candidates = graph[vertex]
    while True:
        new_candidates = set()
        for candidate in candidates:
            passed.add(candidate)
            new_candidates |= graph[candidate] - passed
        if not new_candidates:
            return candidates, distance+1
        candidates = new_candidates
        distance += 1


if __name__ == '__main__':
    main()

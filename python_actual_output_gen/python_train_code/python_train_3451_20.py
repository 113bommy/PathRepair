t = int(input())
for jack in range(t):
    n, x = map(int, input().split())
    adj = [[] for _ in range(n)]
    for _ in range(n - 1):
        a, b = map(int, input().split())
        adj[a - 1].append(b - 1)
        adj[b - 1].append(a - 1)
    # print(adj)
    if len(adj[x - 1]) == 1 or n % 2 == 0:
        print("Ayush",flush=True)
    else:
        print("Ashish",flush=True)

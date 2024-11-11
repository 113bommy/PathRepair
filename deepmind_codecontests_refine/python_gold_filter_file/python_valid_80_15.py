import sys

for _ in range(int(sys.stdin.readline())):
    k = int(sys.stdin.readline())
    data = sys.stdin.readline().rstrip()

    idx = -1
    for i in range(len(data)):
        if data[i] == '0':
            idx = i + 1
            break

    if idx == -1:
        print(f"1 {k - 1} 2 {k}")
    else:
        mid = k // 2
        if idx <= mid:
            print(f"{idx} {k} {idx + 1} {k}")
        else:
            print(f"{1} {idx} {1} {idx - 1}")
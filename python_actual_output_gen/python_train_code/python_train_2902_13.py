for _ in range(int(input())):
    n = int(input())
    array = list(map(int, input().strip().split()))
    zeros = array.count(0); sumo = sum(array)
    if sumo == 0:
        ans = zeros + 1
    else:
        ans = zeros
    print(ans)
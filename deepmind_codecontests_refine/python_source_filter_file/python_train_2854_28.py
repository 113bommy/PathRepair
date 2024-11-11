from itertools import permutations
def main():
    n = int(input())
    l,local,ans = [int(i) for i in input().split()],2,2
    if n == 1: ans = 1
    if n > 2:
        for i in range(2,n):
            if l[i] == l[i-1] + l[i-2]:
                local += 1
            else:
                ans = max(ans,local)
                local = 0
    print(max(ans,local))


if __name__ == "__main__":
    main()
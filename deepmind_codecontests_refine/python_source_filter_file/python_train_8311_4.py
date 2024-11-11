import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**5)

def main():
    N = int(input())
    re = [[] for _ in range(N)]
    for i in range(N-1):
        p = int(input())
        re[p-1].append(i+1)

    def dep(x):
        if re[x] == []:
            return 0
        else:
            cl = []
            for ch in re[x]:
                cl.append(dep(ch))
                cl.sort(reverse = True)
            l = len(cl)
            return max(cl[i]+i+1 for i in range(l))
    
    print(dep(0))
    
if __name__ == "__main__":
    main()

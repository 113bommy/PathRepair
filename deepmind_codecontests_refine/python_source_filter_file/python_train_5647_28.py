def ii():return int(input())
def mi():return map(int,input().split())
def li():return list(mi())
def si():return input()

def main():
    
    for _ in range(ii()):
        n,m=mi()
        for i in range(n):
            for j in range(m):
                if(i==0 and j==0):
                    print("W",end="")
                else:
                    print("B",end="")

        print()    
if __name__ =="__main__":
    main()
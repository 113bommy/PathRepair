n, k=map(int, input().split())
for i in range(n):
            for j in range(n):
                        if i==j:
                                    print(k-1,end=" ")
                        else:
                                    print("1")
            print()
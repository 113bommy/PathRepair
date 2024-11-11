for _ in range(int(input())):
    a,b,c,m = [int(x) for x in input().split()]
    a,b,c = list(sorted([a,b,c]))
    min_pairs = max(0, (c - a - b)-1)
    max_pairs = a-1 + b-1 + c-1
    if  m>=min_pairs and m<=max_pairs:
        print("YES")
    else:
        print("NO")
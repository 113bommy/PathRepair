a=int(input());b=list(map(int,input().split()));print([b[i]+b[i+1] for i in range(a-1)]+[b[-1]])

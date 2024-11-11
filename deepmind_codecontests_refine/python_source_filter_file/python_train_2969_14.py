
week = [52]*4 + [53] *2 + [52]
month = [12]*29 + [4] + [7]

ans = { "week":week ,"month":month}

a,b,c = input().split()
print(ans[c][int(a)-1])
n ,days = map(int, input().split())
arr = list(map(int, input().split()))
key = list(range(1,n+1))
dict1 = dict(zip(key, arr))
sorted_tuples = sorted(dict1.items(), key=lambda item: item[1])
sorted_dict = {k: v for k, v in sorted_tuples}
tot = 0
ans = list()
for k,v in sorted_dict.items():
    if (days-v)>=0:
        days -= v
        ans.append(k)
        tot+=1
    else:
        break
print(tot)
if not ans:
    print(' '.join(str(i) for i in ans))
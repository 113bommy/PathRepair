n,m = input().split()
day = int(input())
ans = [n+" "+m]
last_1, last_2 = n,m
for _ in range(1, day):
    dead, replace =  input().split()
    if dead == last_1:
        ans.append(replace+" " +last_2)
        last_1 = replace
    else:
        ans.append(last_1+" " + replace)
        last_2 = replace
for i in ans:
    print(i)


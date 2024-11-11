s = input()
n = ["Danil", "Olya", "Slava", "Ann", "Nikita"]
cnt = 0
for nn in n:
    if nn in s:
        if(len(s.split(nn))>2):
            cnt = 100
            break
        cnt += 1

if cnt == 1:
    print("YES")
else:
    print("NO")

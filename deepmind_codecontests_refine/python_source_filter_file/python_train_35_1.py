s = input()
nums = set([str(x) for x in range(0, 9+1)])
cnt = dict()
m = -1
ans = 0
days_in_month = {1: 31, 2: 28, 3: 31, 4: 30, 5: 31, 6: 30, 7: 31, 8: 31, 9: 30, 10: 31, 11: 30, 12:31}
for i in range(len(s) - 10):
    q = s[i:i+10]
    if q[0] in nums and q[1] in nums and q[2] == "-":
        if q[3] in nums and q[4] in nums and q[5] == "-": 
            if q[6] in nums and q[7] in nums and q[8] in nums and q[9] in nums:
                try:
                    day = int(q[0:1+1])
                    month = int(q[3:4+1])
                    year = int(q[6:9+1])
                except:
                    continue
                #print(day, month)
                if 0 < month <= 12 and 0 < day <= days_in_month[month] and 2013 <= year <= 2015:
                    try:
                        cnt[q] += 1
                    except:
                        cnt[q] = 0
#print(cnt)
for key in cnt.keys():
    if cnt[key] > m:
        m = cnt[key]
        ans = key
print(ans)
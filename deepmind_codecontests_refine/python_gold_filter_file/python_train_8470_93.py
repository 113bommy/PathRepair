yr=int(input())+1
while len(set(str(yr)))<4:
    yr+=1
print(yr)
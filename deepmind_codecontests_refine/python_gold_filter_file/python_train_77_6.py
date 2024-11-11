dic={'AC':0,'WA':0,'TLE':0,'RE':0}
for _ in range(int(input())) :
  dic[input()]+=1
for key,val in dic.items() :
  print(key+" x " +str(val))
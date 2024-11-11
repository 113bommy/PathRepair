import queue
num=int(input())
q=queue.Queue()
for i in range(1,10):
  q.put(i)
for j in range(num):
  ans=q.get()
  if ans%10!=0:
    q.put(10*ans+(ans%10)-1)
  q.put(10*ans+(ans%10)-1)
  if ans%10!=0:
    q.put(10*ans+(ans%10)-1)
print(ans)
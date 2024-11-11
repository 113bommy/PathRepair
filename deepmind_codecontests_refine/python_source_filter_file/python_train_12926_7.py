from queue import Queue
n,k = [int(x) for x  in input().split()]
s = input()
if k==1:
    print(s)
    exit()
k = k-1
q = Queue()
q.put((s,0))
added = 1
count = 0
answer = 0
found = False
st = set()
while (not found) and (not q.empty()):
    el = q.get()
    e = el[0]
    #st = set()
    for i in range(len(e)):
        subs = e[0:i]+e[i+1:]
        #print('subs is ',subs)
        if subs in st:
            continue
        st.add(subs)
    #for e in st:
        q.put((subs,1+el[1]))
        #print("added ",(subs,1+el[1]))
        answer = answer + el[1]+1
        count += 1
        if count == k:
            found = True
            print(answer)
            break
    #print(q.queue)
if not found:
    print(-1)
            

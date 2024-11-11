class Queue:
    def __init__(self,size):
        self._size = 0
        self._data = [None]*size
        self._front = 0

    def __len__(self):
        return self._size

    def dequeue(self):
        a = self._data[self._front]
        self._data[self._front] = None
        self._front = (self._front + 1)%len(self._data)
        self._size -= 1
        return a

    def enqueue(self,e):
        a = (self._front + self._size)%len(self._data)
        self._data[a] = e
        self._size += 1



n,m = [int(i) for i in input().split()]
q = Queue(n)
a = [q.enqueue(int(i)) for i in input().split()]
cnt = 0
cnt1 = 0
while cnt1 < len(q):
    temp = q.dequeue()
    if temp < 0:
        cnt1 += 1
        cnt += 1
        q.enqueue(temp)
        continue
    else:
        cnt += 1
        cnt1 = 0
        q.enqueue(temp-m)
if cnt%n == 0:
    print(n)
else:
    print(cnt%n)

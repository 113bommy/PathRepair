from copy import deepcopy

class PriorityQueue():
    def __init__(self):
        self.elements = [(0, None)]
        self.size = 0
        self.capacity = 1000

    def push(self, item):
        # the first element of item is the index, it must be digits
        self.size += 1
        self.elements.append(item)
        i = self.size
        
        while self.elements[i//2][0]>item[0]:
            self.elements[i] = self.elements[i//2]
            i = i // 2
        self.elements[i] = item
    def poll(self):
        if self.size <= 0:
            return None
        min_element = deepcopy(self.elements[1])
        last_element = self.elements.pop()
        self.size -= 1
        i = 1
        while (i*2)<=self.size:
            child = i * 2 # left child
            if (child != self.size and (self.elements[child+1][0] < self.elements[child][0])):
                child += 1
            if last_element[0] > self.elements[child][0]:
                self.elements[i] = self.elements[child]
            else:
                break
            
            i = child
        if self.size > 0:
            self.elements[i] = last_element
        return min_element




import heapq


n,k = tuple(map(int, input().split(' ')))
s = []
for i in range(n):
    t = tuple(map(int, input().split(' ')))
    s.append(t)


def get_beauty(e):
    return e[1]
s.sort(reverse=True, key=get_beauty)
max_score = 0
sum_len = 0
heap = []
try:
    for i in range(n):
        length = s[i][0]
        beauty = s[i][1]
        heapq.heappush(heap,length)
        sum_len += length
        if i > k:
            sum_len-=heapq.heappop(heap)
        score = (sum_len) * beauty
        max_score = max(max_score, score)
except Exception as e:
    print(e)
    

print(max_score)
    
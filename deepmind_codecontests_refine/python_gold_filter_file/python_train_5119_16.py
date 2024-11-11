class BinHeap():

    def __init__(self):
        self.heap = []

    def get_max(self):
        if len(self.heap) > 0:
            return self.heap[0]

    def add_elem(self, elem):
        self.heap.append(elem)
        index = len(self.heap) - 1
        while index > 0 and self.heap[index] > self.heap[(index - 1) // 2]:
            self.heap[index], self.heap[(index - 1) // 2] = self.heap[(index - 1) // 2], self.heap[index]
            index = (index - 1) // 2

    def delete_min(self):
        if len(self.heap) == 0:
            pass
        else:
            elem = self.heap[0]
            self.heap[0], self.heap[len(self.heap) - 1] = self.heap[len(self.heap) - 1], self.heap[0]
            self.heap.pop()
            self.heapfy(0)
            return elem

    def heapfy(self, index):
        left = index * 2 + 1
        right = index * 2 + 2
        size_heap = len(self.heap)

        if size_heap > left and self.heap[left] > self.heap[index]:
            elem = left
        else:
            elem = index

        if size_heap > right and self.heap[right] > self.heap[elem]:
            elem = right

        if elem != index:
            self.heap[elem], self.heap[index] = self.heap[index], self.heap[elem]
            self.heapfy(elem)


arr = list(map(int, input().split()))
n, m = arr[0], arr[1]
arr = list(map(int, input().split()))
heap = BinHeap()
heap.heap
answers = []
s = 0
for i in range(n):
    ans = i - len(heap.heap)
    times = []
    if s + arr[i] > m:
        while s + arr[i] > m:
            times.append(heap.delete_min())
            ans += 1
            s -= times[-1]
        for elem in times:
            heap.add_elem(elem)
            s += elem
        if heap.get_max() > arr[i]:
            s -= heap.delete_min()
            heap.add_elem(arr[i])
            s += arr[i]
    else:
        s += arr[i]
        heap.add_elem(arr[i])
    answers.append(ans)

ans = ''
for elem in answers:
    ans += str(elem) + ' '
print(ans[:-1])



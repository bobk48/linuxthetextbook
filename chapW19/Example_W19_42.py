import queue

q = queue.LifoQueue()
for i in range(7):
    q.put(i)
while not q.empty():
    print(q.get(), end=' ')
#    print()

import queue as Q

q = Q.PriorityQueue()
q.put(15)
q.put(18)
q.put(4)
q.put(9)
while not q.empty():
	print (q.get(),)

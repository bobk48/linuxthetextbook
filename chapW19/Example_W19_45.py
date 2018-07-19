from threading import Thread
import time
import random
import queue

q_buffer = queue.Queue()

class Producer(Thread):
    def run(self):
        numbers = range(5)
        global q_buffer 
        while True:
            actual_number = random.choice(numbers)
            q_buffer.put(actual_number)
            print ("Produced thread", actual_number)
            time.sleep(random.random())


class Consumer(Thread):
    def run(self):
        global q_buffer 
        while True:
            actual_number_gotten = q_buffer.get()
            q_buffer.task_done()
            print ("Consumed thread", actual_number_gotten)
            time.sleep(random.random())


Producer().start()
Consumer().start()

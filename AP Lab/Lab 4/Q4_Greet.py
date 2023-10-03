import time
name = input("Enter Name: ")
epoch = int(time.time())
current_time = time.localtime(epoch)
print(f'{current_time.tm_hour}h: {current_time.tm_min}m: {current_time.tm_sec}s')
 
if current_time.tm_hour > 20:
    print("Good Night", name)
elif current_time.tm_hour >16:
    print("Good Evening", name)
elif current_time.tm_hour > 11:
    print("Good Afternoon", name)
elif current_time.tm_hour > 4:
    print("Good Morning", name)
else:
    print("Good Night", name)
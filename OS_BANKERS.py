CODE:
def findID(finish, n, id):
 flag = 0
 for i in range(n):
 if finish[i] == 0:
 flag = 1
 break
 if flag == 0:
 return -1
 else:
 if 0 <= id < n and finish[id] == 1:
 return -2
 else:
 return 0
def computeAvailable(total_resources, alloc_matrix, process_Count, resource_Count)
 total_resources = []
 for j in range(resource_Count):
 total_resources.append(int(input()))

 avail = [total_resources[j] - sum(alloc_matrix[i][j] for i in range(process_Count)) for j in
range(resource_Count)]
 return avail
process_Count = int(input())
resource_Count = int(input())
max_matrix = []
alloc_matrix = []
need_matrix = []
for i in range(process_Count):
 temp = []
 for j in range(resource_Count):
 temp.append(int(input()))
 max_matrix.append(temp)
for i in range(process_Count):
 temp = []
 for j in range(resource_Count):
 temp.append(int(input()))
 alloc_matrix.append(temp)
for i in range(process_Count):
 temp = []
 for j in range(resource_Count):
 temp.append(max_matrix[i][j] - alloc_matrix[i][j])
 need_matrix.append(temp)
total_resources = []
for j in range(resource_Count):
 total_resources.append(int(input()))
avail = [total_resources[j] - sum(alloc_matrix[i][j] for i in range(process_Count)) for j in
range(resource_Count)]
work = avail[:]
finish = [0] * process_Count
print("The system is safe.\n")
print("Max Alloc Need Avail")
for i in range(process_Count):
 for j in range(resource_Count):
 print(max_matrix[i][j], end=" ")
 print(" ", end="")
 for j in range(resource_Count):
 print(alloc_matrix[i][j], end=" ")
 print(" ", end="")
 for j in range(resource_Count):
 print(need_matrix[i][j], end=" ")
 print(" ", end="")
 if i == 0:
 for j in range(resource_Count):
 print(avail[j], end=" ")
 print()
safe = []
k = 0
id = 0
while True:
 pid = 0
 flag = 0
 for i in range(process_Count):
 if finish[i] == 0:
 flag = 1
 break
 if flag == 0:
 pid = -1
 else:
 if 0 <= id < process_Count and finish[id] == 1:
 pid = -2
 if pid == -1:
 break
 elif pid == -2:
 id = (id + 1) % process_Count
 else:
 flag = 0
 for j in range(resource_Count):
 if need_matrix[id][j] > work[j]:
 flag = 1
 break
 if flag == 0:
 for j in range(resource_Count):
 work[j] += alloc_matrix[id][j]
 finish[id] = 1
 safe.append("P" + str(id))
 id = (id + 1) % process_Count
print("\nSafe Seequence is : ('" + "', '".join(safe) + "')")
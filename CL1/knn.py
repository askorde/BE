import math
import csv

def knn(k, train_data, train_label, test_data):
	ds = []
	for i in range(len(train_data)):
		ds.append((get_dist(train_data[i], test_data),train_label[i]))
	nn = sorted(ds)[:k]
	a={}
	for i in range(k):
		a[nn[i][1]] = 1 if nn[i][1] not in a else a[nn[i][1]]+1
		
	print("Predicted label:",max(a))	
	
def get_dist(data1, data2):
	distance = 0
	length = len(data1)
	for x in range(length):
		distance += pow((float(data1[x]) - float(data2[x])), 2)
	return math.sqrt(distance)

#dataset link https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data	
f = open('iris.data', 'r')
data = f.readlines()
feat = [data[i].strip().split(',')[:-1] for i in range(len(data))]
labels = [data[i].strip().split(',')[-1] for i in range(len(data))]
#print(labels)
knn(3,feat[:-1], labels[:-1], feat[-1])
print("Actual label:", labels[-1])

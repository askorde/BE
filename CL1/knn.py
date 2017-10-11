import math
import csv
import random

def knn(k, train_data, train_label, test_data):
	ds = []
	for i in range(len(train_data)):
		ds.append((get_dist(train_data[i], test_data),train_label[i]))
	nn = sorted(ds)[:k]
	a={}
	for i in range(k):
		a[nn[i][1]] = 1 if nn[i][1] not in a else a[nn[i][1]]+1
		
	return max(a)	
	
def get_dist(data1, data2):
	distance = 0
	length = len(data1)
	for x in range(length):
		distance += pow((float(data1[x]) - float(data2[x])), 2)
	return math.sqrt(distance)

def loadDataset(filename, split ):
	trainingSet=[]
	testSet=[]
	f = open('iris.data', 'r')
	data = f.readlines()
	dataset = [data[i].strip().split(',') for i in range(len(data)) ]
	
	for x in range(len(dataset)):
		for y in range(4):
			dataset[x][y] = float(dataset[x][y])
		if random.random() < split:
			trainingSet.append(dataset[x])
		else:
			testSet.append(dataset[x])
	
	X_train = [trainingSet[i][:-1] for i in range(len(trainingSet))]
	X_test = [testSet[i][:-1] for i in range(len(testSet))]
	
	y_train = [trainingSet[i][-1] for i in range(len(trainingSet))]
	y_test = [testSet[i][-1] for i in range(len(testSet))]
	
	return X_train,X_test,y_train,y_test           
	           
	           
#dataset link https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data
split = 0.75	
X_train, X_test, y_train, y_test = loadDataset('iris.data',split)

print("Split ratio: ", split)

preds = []
c = 0
for i in range(len(y_test)):
	pred = 	knn(3,X_train,y_train,X_test[i])
	#preds.append(pred)
	print("Predicted label: ", pred, " Actual label: ", y_test[i])
	if(pred == y_test[i]):
		c = c+1		
	
print("\n\nAccuracy = ", (c/len(y_test)))	

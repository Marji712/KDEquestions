// Marji Symonds
// Maximum Sum of Contiguous Subarrays

function maxContSum(array) {
	var maxSum = 0
	var currSum = 0

	for (let number of array) {
		currSum = Math.max(0, currSum + number)
		maxSum = Math.max(maxSum, currSum)
	}

	return maxSum
}

console.log(maxContSum([0, -3, 2, 1, 4, 5, 9, -3, 2]))
console.log(maxContSum([1, 2, 5, -5]))
console.log(maxContSum([1, 2, 5, 0, 7, 3]))
console.log(maxContSum([-2, 7, 4, -1]))
console.log(maxContSum([0, 0, 0]))
console.log(maxContSum([]))


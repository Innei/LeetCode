const findMedianSortedArrays = function(nums1, nums2) {
    const arr = [...nums1,...nums2].sort(function(a,b){return a-b;})
    if (arr.length % 2) {
        return arr[Math.floor(arr.length / 2)]
    }
    else {
        return (arr[Math.floor(arr.length / 2)] + (arr[Math.floor(arr.length / 2) - 1]) ) /2
    }
    
};
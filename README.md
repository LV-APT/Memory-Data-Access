# Memory-Data-Access
        实现LV Data 与C语言数据内存格式的转换，以及LV内存数据块的读取
## 函数说明：  
* Mem_DataToU8Array.vi: 实现LvData转换至内存格式的U8数组  
* Mem_U8ArrayToData.vi: 实现内存格式的U8数组转换为Lv支持的数据格式  
* Mem_ObtainQueue.vi: 为了实现通过内存地址传递和访问数据，创建FIFO实现内存的申请及释放  
* Mem_Release.vi: 释放数据交互申请的内存空间。  
* Mem_XXXArray: 利用LabVIEW中的moveblock函数，实现内存数据块的读取，从而获取数据。  
## 支持的数据类型:  
* I8, I16, I32, I64, U8, U16, U32, U64, SGL, DBL, String, Boolean, Path, TimeStamp, WaveForm  
* 以上面元素组成的一维Array  
* 以上元素组成的Cluster  
## 注意：
* 所有的数组只传递长度以及首地址：Len 和 Addr. WaveformArray通过递归保存  
* Mem_DataToU8Array.vi需要配合Mem_Obtain.vi以及Mem_Release.vi使用，目的是获取数据内存地址，并通过FIFO管理内存，否则会存在内存泄露。  
* 由于通过内存地址方式访问数据，因此不支持RPC远程调用访问  


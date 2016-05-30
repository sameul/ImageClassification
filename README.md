# httpserver-v2
这是一个基于web的图片识别系统，系统采用的模式是BS，采用的深度学习框架是caffe。
如果你想使用的话，首先需要正确安装完caffe框架，其次需要修改doClassification.c中的
sprintf(arg1, "/home/john/caffe/build/examples/cpp_classification/classification.bin \
  /home/john/caffe/models/bvlc_reference_caffenet/deploy.prototxt \
  /home/john/caffe/models/bvlc_reference_caffenet/bvlc_reference_caffenet.caffemodel \
  /home/john/caffe/data/ilsvrc12/imagenet_mean.binaryproto \
  /home/john/caffe/data/ilsvrc12/synset_words.txt %s > infile", arg0);
  部分相应的文件的路径。

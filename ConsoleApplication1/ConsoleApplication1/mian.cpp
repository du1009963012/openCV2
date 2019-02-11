#include <opencv2\opencv.hpp>
#include <iostream>
#include <fstream>


using namespace std;
using namespace cv;
int main(int argc,char** argv) {
	Mat src, dst;
	Mat src1, src2,dst1,dst2;
	Mat out_imag;
	//FILE *file_out_creat;
	//file_out_creat = fopen("G: / picture / bd_logo1.txt","w+");
	//fclose(file_out_creat);
	//ofstream file_out("bd_logo1.txt");
	//file_out << 132 << endl;
	//file_out.close();
	/*if (!file_out.is_open()) {
		cout << "文件打开失败！"<< file_out.is_open();
		return 0;
	}*/
	src = imread("G:/picture/bd_logo1.png");
	cout << "src.size()" << src.size() << " src.type()" << src.type() << "src.depth()" << src.depth()<<endl;
	src1 = imread("back_image_4.jpg");
	src2 = imread("back_image_9.jpg");

	if (!src.data||!src1.data||!src2.data) {
		cout << "文件为空！";
		return -1;
	}
	resize(src1,src1,src1.size()/3);
	resize(src2,src2, src2.size() / 3); 
	dst = Mat(src.rows,src.cols,CV_8UC3,Scalar(0,0,0));
	int row, col;
	for (row = 0; row < src.rows;row++) {
		 uchar* i= src.ptr<uchar>(row);
		uchar* out= dst.ptr<uchar>(row);
		for (col = 0; col < src.cols;col++) {
			//out[col*src.channels()-3 ] = i[col*src.channels()-3];//B通道的值
			//out[c ol*src.channels()-2] = i[col*src.channels()-2];//G通道的值
			//out[col*src.channels()-1] = i[col*src.channels()-1];//R通道的值
			//out[col*src.channels()] = i[col*src.channels()];
			out[col*src.channels()+2] = i[col*src.channels()+2];
			//if (col % 6 == 0)file_out << "\n";
			//file_out << "row:" << row << " col:" << col << " " << src.at<Vec3b>(row, col);
			if (src.at<Vec3b>(row, col)[0] != 255 && src.at<Vec3b>(row, col)[1] != 255 && src.at<Vec3b>(row, col)[2] != 255) {
			/*	file_out <<"\n"<< "row" << row << "  col:"<<col << "\n";
				file_out << dst.at<Vec3b>(row, col);*/
			//file_out<< "row:" << row << "  col:" << col << "\t" << dst.at<Vec3b>(row, col);
		
			}

		}
	}
	
	cout << "src1.size()" << src1.size() <<" src1.type()"<<src1.type() <<"src1.depth()"<<src1.depth()<<"  src2.size()" << src2.size() <<"src2.type()"<<src2.type() <<endl;
	if (src1.size() == src2.size()) {
		addWeighted(src1,0.4,src2,0.6,-10,dst1);
		sum(src1);
	}

	//namedWindow("src",WINDOW_AUTOSIZE);
	//imshow("src",src);
	imshow("src1", src1);
	imshow("src2",src2);
	imshow("dst1",dst1);
	//file_out.close();
	waitKey(0);
	return 0;
}

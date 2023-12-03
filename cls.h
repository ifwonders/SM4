#pragma once
class _32BitData
{
	//所有32位字数据类型的父类
public :
	int sub;
	unsigned int data;
};

class MK : public _32BitData
{
	//128bit四分为32bit密钥 总共四个
public:
	void setMK(int num, unsigned int cont)
	{
		sub = num;
		data = cont;
	}
private:
};

class FK : public _32BitData
{
	//系统参数 每一项表示32位的字
public:
	void setFK(int num, unsigned int cont)
	{
		sub = num;
		data = cont;
	}
private:
};

class CK : public _32BitData
{
	//固定参数 用于密钥扩展算法 每一项都为32位的字
public:
	void setCK(int num, unsigned int cont) {
		sub = num;
		data = cont;
	}
private:
};

class rk : public _32BitData
{
	//轮密钥 每一项都为32位的字 由加密密钥通过密钥扩展算法生成
public:
	void setrk(int num, unsigned int cont){
		sub = num;
		data = cont;
	}
	void generateKi(MK MKi, FK FKi) {
		data = MKi.data xor FKi.data;
	}
private:
};

class TData : public _32BitData
{
public:
	unsigned char AData[4];
	unsigned char BData[4];
	void generateA(rk Ks[4], CK CKi) {
		data = Ks[1].data xor Ks[2].data xor Ks[3].data xor CKi.data;
		for (int i = 0; i < 4; ++i) 
			AData[i] = (data >> (-8 * i + 24)) & 0xff;
	}
private:
};

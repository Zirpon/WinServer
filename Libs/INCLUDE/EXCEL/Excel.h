#pragma once

#include <comutil.h>
#include <string>

class CExcelImpl;

class CExcel
{
private:
    //disable copying
    CExcel(const CExcel& other);
    const CExcel& operator = (const CExcel& ohter);

    CExcelImpl* m_impl; //p-impl implemention
public:
	CExcel(void);
	//static CExcelApp& _GetInstance();
	~CExcel(void);

//�����ӿں���
public:
	//////////////////////////////////////////////////////////////////////////
	//remark:		��һ��EXCEL����
	//params:		1
	//par1:			���ļ�·��
	//ret:			�򿪳ɹ�:true ��ʧ��:false
	//////////////////////////////////////////////////////////////////////////
	bool Open(const char* filePath);

	//////////////////////////////////////////////////////////////////////////
	//remark:		�رյ�ǰ�򿪵�EXCEL����
	//params:		0
	//ret:			void
	//////////////////////////////////////////////////////////////////////////
	void Close();

	//////////////////////////////////////////////////////////////////////////
	//remark:		���浱ǰ�򿪵�EXCEL�ļ�
	//params:		1
	//par1:			�����ļ�·��
	//ret:			void
	//////////////////////////////////////////////////////////////////////////
	void SaveAs(const char* filePath);

	//////////////////////////////////////////////////////////////////////////
	//remark:		��յ�ǰ��EXCEL�ļ�������
	//params:		0
	//ret:			void
	//////////////////////////////////////////////////////////////////////////
	void Reset();

	//////////////////////////////////////////////////////////////////////////
	//remark:		EXCEL�Ƿ񱻳�ʼ��
	//params:		0
	//ret:			�Ѿ���ʼ��:true��δ��ʼ��:false
	//////////////////////////////////////////////////////////////////////////
	bool IsInitialized();
	
	//////////////////////////////////////////////////////////////////////////
	//remark:		���EXCELӦ����
	//params:		0
	//ret:			EXCELӦ����
	//////////////////////////////////////////////////////////////////////////
    std::string GetAppName();

	//////////////////////////////////////////////////////////////////////////
	//remark:		����EXCEL�ļ�����
	//params:		0
	//ret:			void
	//////////////////////////////////////////////////////////////////////////
	void SetCaption(const char* capName);

	//////////////////////////////////////////////////////////////////////////
	//remark:		���EXCEL�ļ�����
	//params:		0
	//ret:			EXCEL�ļ�����
	//////////////////////////////////////////////////////////////////////////
	std::string GetCaption();

	//////////////////////////////////////////////////////////////////////////
	//remark:		����ָ��sheet��Ԫ������
	//params:		4
	//par1:			sheet��ţ�������sheet�����ַ�����Ҳ������sheet index����1��ʼ
	//par2:			��Ԫ����index����1��ʼ
	//par3:			��Ԫ����index����1��ʼ
	//par4:			�����õ�ֵ
	//ret:			�ɹ�:true , ʧ��:false
	//////////////////////////////////////////////////////////////////////////
	bool SetItem(const _variant_t& sheetIndex, const _variant_t& rowIndex, const _variant_t& colIndex, const _variant_t& val);

	//////////////////////////////////////////////////////////////////////////
	//remark:		���õ�ǰsheet��Ԫ������
	//params:		3
	//par1:			��Ԫ����index����1��ʼ
	//par2:			��Ԫ����index����1��ʼ
	//par3:			�����õ�ֵ
	//ret:			void
	//////////////////////////////////////////////////////////////////////////
	void SetItem(const _variant_t& rowIndex, const _variant_t& colIndex, const _variant_t& val);

	//////////////////////////////////////////////////////////////////////////
	//remark:		��õ�ǰsheet��Ԫ������
	//params:		2
	//par1:			��Ԫ����index����1��ʼ
	//par2:			��Ԫ����index����1��ʼ
	//ret:			��Ԫ��ֵ
	//////////////////////////////////////////////////////////////////////////
	_variant_t GetItem(const _variant_t& rowIndex, const _variant_t& colIndex);

	//////////////////////////////////////////////////////////////////////////
	//remark:		����ָ��sheet��Ԫ������
	//params:		3
	//par1:			sheet��ţ�������sheet�����ַ�����Ҳ������sheet index����1��ʼ
	//par2:			��Ԫ����index����1��ʼ
	//par3:			��Ԫ����index����1��ʼ
	//ret:			��Ԫ��ֵ
	//////////////////////////////////////////////////////////////////////////
	_variant_t GetItem(const _variant_t& sheetIndex, const _variant_t& rowIndex, const _variant_t& colIndex);

	//////////////////////////////////////////////////////////////////////////
	//remark:		��õ�ǰsheet������
	//params:		0
	//ret:			��ǰsheet������
	//////////////////////////////////////////////////////////////////////////
	std::string GetCurrentSheetName();

	//////////////////////////////////////////////////////////////////////////
	//remark:		���õ�ǰsheet������
	//params:		1
	//par1:			sheet����
	//ret:			void
	//////////////////////////////////////////////////////////////////////////
	void SetCurrentSheetName(const char* sheetName);
	
	//////////////////////////////////////////////////////////////////////////
	//remark:		ָ��sheetΪ��ǰsheet
	//params:		1
	//par1:			ָ��sheet�ı��,������sheet�����ַ�����Ҳ������sheet index����1��ʼ
	//ret:			�ɹ�:true , ʧ��:false
	//////////////////////////////////////////////////////////////////////////
	bool ActiveSheet(const _variant_t& sheet);

	//////////////////////////////////////////////////////////////////////////
	//remark:		���sheet����
	//params:		0
	//ret:			sheet����
	//////////////////////////////////////////////////////////////////////////
	long GetSheetsCount();

	//////////////////////////////////////////////////////////////////////////
	//remark:		��õ�ǰsheet�������
	//params:		0
	//ret:			sheet�������
	//////////////////////////////////////////////////////////////////////////
	long GetCurrentSheetIndex();

	//////////////////////////////////////////////////////////////////////////
	//remark:		����insertedSheetName��sheetǰ
	//params:		2
	//par1:			���뵽��sheet��ǰ��
	//par2:			����sheet������
	//ret:			�ɹ�:true , ʧ��:false
	//////////////////////////////////////////////////////////////////////////
	bool InsertSheetBefore(const _variant_t& sheet, const char* insertedSheetName);

	//////////////////////////////////////////////////////////////////////////
	//remark:		����insertedSheetName��sheet��
	//params:		2
	//par1:			���뵽��sheet�ĺ���
	//par2:			����sheet������
	//ret:			�ɹ�:true , ʧ��:false
	//////////////////////////////////////////////////////////////////////////
	bool InsertSheetAfter(const _variant_t& sheet, const char* insertedSheetName);

	//////////////////////////////////////////////////////////////////////////
	//remark:		��sheet�б�pushһ��sheet
	//params:		1
	//par1:			����sheet������
	//ret:			void
	//////////////////////////////////////////////////////////////////////////
	void PushSheet(const char* pushedSheetName);

	//////////////////////////////////////////////////////////////////////////
	//remark:		ɾ��һ��sheet
	//params:		1
	//par1:			��ɾ��sheet,������sheet�����ַ�����Ҳ������sheet index����1��ʼ
	//ret:			�ɹ�:true , ʧ��:false
	//////////////////////////////////////////////////////////////////////////
	bool DeleteSheet(const _variant_t& deletedSheet);

	//////////////////////////////////////////////////////////////////////////
	//remark:		����һ��sheet
	//params:		1
	//par1:			�����ҵ�sheet,������sheet�����ַ�����Ҳ������sheet index����1��ʼ
	//ret:			sheet�±�����
	//////////////////////////////////////////////////////////////////////////
	int  FindSheet(const _variant_t& sheet);

	//////////////////////////////////////////////////////////////////////////
	//remark:		��õ�ǰ����������
	//params:		0
	//ret:			��������
	//////////////////////////////////////////////////////////////////////////
	std::string GetCurrentWorkBookName();

	//////////////////////////////////////////////////////////////////////////
	//remark:		��õ�ǰ����������
	//params:		0
	//ret:			����������
	//////////////////////////////////////////////////////////////////////////
	long GetWorkBooksCount();

	std::string GetCurrentRangeName();
	long GetCurrentRangeCount();
};

//#define EXCEL CExcelApp::_GetInstance()
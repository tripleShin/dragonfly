#include "logging.h"

namespace drf {
	logging::logging(){}

	std::string logging::setUpDirectory(){

		//現在時刻取得
		time_t now = time(NULL);
		struct tm *pnow = localtime(&now);

		// フォルダ名格納
		std::string directoryName = 
		"log/" + std::to_string( pnow->tm_year + 1900 )
		+ std::to_string( pnow->tm_mon + 1 ) +　std::to_string( pnow->tm_mday ) 
		+ std::to_string( pnow->tm_hour ) + std::to_string( pnow->tm_min ) 
		+ std::to_string( pnow->tm_sec );
		
		// logフォルダが無ければ作成
		if( mkdir( "log",0777 ) == 0 ){
			std::cout << "logフォルダを作成しました。" << std::endl;
    	}else{
    		std::cout << "logフォルダは既に存在します。" << std::endl;
    	}

    	// 今回のデータ用フォルダ作成
    	if(mkdir( directoryName.c_str() ,0777 )==0){
    		
    		std::cout << directoryName << "フォルダを作成しました。" << std::endl;

    	}else{

    		std::cout << "フォルダの作成に失敗しました。" << std::endl;
   			
    	}

		return directoryName + "/";
	}

	void logging::logString( std::string text, std::string directoryName){
		
		static int i = 0;
		std::ofstream outputLog;

		//ファイルオープン
		outputLog.open( directoryName, std::ios_base::out | std::ios_base::app);

		//ロギング
		outputLog << i << " " << text << std::endl;

		//終了処理：ファイルを閉じる
		outputLog.close();

		i++;		

	}


	logging::~logging(){}
} // drf
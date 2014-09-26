// -*- C++ -*-
/*!
 * @file  WordControl.h
 * @brief WordControlomponent
 * @date  $Date$
 *
 * $Id$
 */

#ifndef WORDCONTROL_H
#define WORDCONTROL_H

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>
#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

#include <fstream>

#include "WriterSVC_impl.h"

#include "myWord.h"
#include "WordTask.h"

// Service implementation headers
// <rtc-template block="service_impl_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">

// </rtc-template>

using namespace RTC;






/*!
 * @class WordControl
 * @brief WordRTComponent
 *
 */
class WordControl
  : public RTC::DataFlowComponentBase
{
 public:
  /**
	*@brief �R���X�g���N�^
	* @param manager
	*/
  WordControl(RTC::Manager* manager);

  /**
   * @brief �f�X�g���N�^
   */
  ~WordControl();

  /**
   * @brief �R���t�B�M�����[�V�����p�����[�^���X�V���ꂽ�Ƃ��Ƀt�@�C�����ēǂݍ��݂���֐�
   */
  void WordControl::ConfigUpdate();

  /**
   *@brief �t�@�C�����̃R���t�B�M�����[�V�����p�����[�^�ύX�̊֐�
   * @param FP
   */
   void SetFilePath(std::string FP);

  // <rtc-template block="public_attribute">
  
  // </rtc-template>

  // <rtc-template block="public_operation">
  
  // </rtc-template>

  /**
  *@brief �����������p�R�[���o�b�N�֐�
  * @return 
  */
   virtual RTC::ReturnCode_t onInitialize();

  /**
   *@brief �I�������̃R�[���o�b�N�֐�
   * @return 
   */
   virtual RTC::ReturnCode_t onFinalize();

  /***
   *
   * The startup action when ExecutionContext startup
   * former rtc_starting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStartup(RTC::UniqueId ec_id);

  /***
   *
   * The shutdown action when ExecutionContext stop
   * former rtc_stopping_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onShutdown(RTC::UniqueId ec_id);

  /**
   *@brief ���������̃R�[���o�b�N�֐�
   * @param ec_id
   * @return 
   */
   virtual RTC::ReturnCode_t onActivated(RTC::UniqueId ec_id);

  /**
   *@brief �s���������̃R�[���o�b�N�֐�
   * @param ec_id
   * @return 
   */
   virtual RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id);

  /**
   *@brief ���������p�R�[���o�b�N�֐�
   * @param ec_id
   * @return 
   */
   virtual RTC::ReturnCode_t onExecute(RTC::UniqueId ec_id);

  /***
   *
   * The aborting action when main logic error occurred.
   * former rtc_aborting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onAborting(RTC::UniqueId ec_id);

  /***
   *
   * The error action in ERROR state
   * former rtc_error_do()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onError(RTC::UniqueId ec_id);

  /***
   *
   * The reset action that is invoked resetting
   * This is same but different the former rtc_init_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onReset(RTC::UniqueId ec_id);
  
  /***
   *
   * The state update action that is invoked after onExecute() action
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStateUpdate(RTC::UniqueId ec_id);

  /***
   *
   * The action that is invoked when execution context's rate is changed
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onRateChanged(RTC::UniqueId ec_id);


 protected:
  // <rtc-template block="protected_attribute">
  
  // </rtc-template>

  // <rtc-template block="protected_operation">
  
  // </rtc-template>

  // Configuration variable declaration
  // <rtc-template block="config_declare">

  // </rtc-template>

  // DataInPort declaration
  // <rtc-template block="inport_declare">
  RTC::TimedString m_word;	/**<�@@brief  */
  
  InPort<RTC::TimedString> m_wordIn;	/**<�@@brief  */
  RTC::TimedFloat m_fontSize;	/**<�@@brief  */
 
  InPort<RTC::TimedFloat> m_fontSizeIn;	/**<�@@brief  */
  RTC::TimedString m_fontName;	/**<�@@brief  */
  
  InPort<RTC::TimedString> m_fontNameIn;	/**<�@@brief  */
  RTC::TimedShort m_wsCharacter;	/**<�@@brief  */
  
  InPort<RTC::TimedShort> m_wsCharacterIn;	/**<�@@brief  */
  RTC::TimedShort m_wsWord;	/**<�@@brief  */
  
  InPort<RTC::TimedShort> m_wsWordIn;	/**<�@@brief  */
  RTC::TimedShort m_wsLine;	/**<�@@brief  */
  
  InPort<RTC::TimedShort> m_wsLineIn;	/**<�@@brief  */
  RTC::TimedShort m_wsParagraph;	/**<�@@brief  */
  
  InPort<RTC::TimedShort> m_wsParagraphIn;	/**<�@@brief  */
  RTC::TimedShort m_wsWindow;	/**<�@@brief  */
  
  InPort<RTC::TimedShort> m_wsWindowIn;	/**<�@@brief  */
  RTC::TimedShort m_wsScreen;	/**<�@@brief  */
 
  InPort<RTC::TimedShort> m_wsScreenIn;	/**<�@@brief  */
  RTC::TimedRGBColour m_Char_color;	/**<�@@brief  */
  
  InPort<RTC::TimedRGBColour> m_Char_colorIn;	/**<�@@brief  */

  RTC::TimedBoolean m_MovementType;	/**<�@@brief  */
  
  InPort<RTC::TimedBoolean> m_MovementTypeIn;	/**<�@@brief  */

  RTC::TimedBoolean m_Italic;	/**<�@@brief  */
  
  InPort<RTC::TimedBoolean> m_ItalicIn;	/**<�@@brief  */

  RTC::TimedBoolean m_Bold;	/**<�@@brief  */
  
  InPort<RTC::TimedBoolean> m_BoldIn;	/**<�@@brief  */


  

  RTC::TimedBoolean m_Underline;	/**<�@@brief  */
  
  InPort<RTC::TimedBoolean> m_UnderlineIn;	/**<�@@brief  */

  RTC::TimedBoolean m_Shadow;	/**<�@@brief  */
  
  InPort<RTC::TimedBoolean> m_ShadowIn;	/**<�@@brief  */

  RTC::TimedBoolean m_Strikeout;	/**<�@@brief  */
  
  InPort<RTC::TimedBoolean> m_StrikeoutIn;	/**<�@@brief  */

  RTC::TimedBoolean m_Contoured;	/**<�@@brief  */
  
  InPort<RTC::TimedBoolean> m_ContouredIn;	/**<�@@brief  */

  RTC::TimedBoolean m_Emphasis;	/**<�@@brief  */
 
  InPort<RTC::TimedBoolean> m_EmphasisIn;	/**<�@@brief  */

  RTC::TimedRGBColour m_Back_color;	/**<�@@brief  */
  
  InPort<RTC::TimedRGBColour> m_Back_colorIn;	/**<�@@brief  */
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  RTC::TimedString m_selWord;	/**<�@@brief  */
  
  OutPort<RTC::TimedString> m_selWordOut;
  RTC::TimedString m_copyWord;	/**<�@@brief  */
  
  OutPort<RTC::TimedString> m_copyWordOut;	/**<�@@brief  */


  
  // </rtc-template>

  // CORBA Port declaration
  // <rtc-template block="corbaport_declare">
  
  // </rtc-template>

  RTC::CorbaPort m_WriterPort;	/**<�@@brief  */
  
  // </rtc-template>

  // Service declaration
  // <rtc-template block="service_declare">
  /*!
   */
  mWriterSVC_impl m_writer;	/**<�@@brief  */

  // Service declaration
  // <rtc-template block="service_declare">
  
  // </rtc-template>

  // Consumer declaration
  // <rtc-template block="consumer_declare">
  
  // </rtc-template>

  std::string file_path;	/**<�@@brief  */
  float fontsize;	/**<�@@brief  */
  std::string fontname;	/**<�@@brief  */
  int Char_Red;	/**<�@@brief  */
  int Char_Blue;	/**<�@@brief  */
  int Char_Green;	/**<�@@brief  */
  int Italic;	/**<�@@brief  */
  int Bold;	/**<�@@brief  */
  std::string Code;	/**<�@@brief  */

  int Underline;	/**<�@@brief  */
  int Shadow;	/**<�@@brief  */
  int Strikeout;	/**<�@@brief  */
  int Contoured;	/**<�@@brief  */
  int Emphasis;	/**<�@@brief  */

  int Back_Red;	/**<�@@brief  */
  int Back_Green;	/**<�@@brief  */
  int Back_Blue;	/**<�@@brief  */


 private:
	 std::ofstream ofs;
	 WordTask *wt;


  // <rtc-template block="private_attribute">
  
  // </rtc-template>

  // <rtc-template block="private_operation">
  
  // </rtc-template>

};




extern "C"
{
  DLL_EXPORT void WordControlInit(RTC::Manager* manager);
};

#endif // WORDRTC_H

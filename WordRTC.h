// -*- C++ -*-
/*!
 * @file  WordRTC.h
 * @brief WordRTComponent
 * @date  $Date$
 *
 * $Id$
 */

#ifndef WORDRTC_H
#define WORDRTC_H

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>
#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

#include "myWord.h"

// Service implementation headers
// <rtc-template block="service_impl_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">

// </rtc-template>

using namespace RTC;






/*!
 * @class WordRTC
 * @brief WordRTComponent
 *
 */
class WordRTC
  : public RTC::DataFlowComponentBase
{
 public:
  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  WordRTC(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~WordRTC();

  //コンフィギュレーションパラメータが更新されたときにファイルを再読み込みする関数
  void WordRTC::ConfigUpdate();

  // <rtc-template block="public_attribute">
  
  // </rtc-template>

  // <rtc-template block="public_operation">
  
  // </rtc-template>

  /***
   *
   * The initialize action (on CREATED->ALIVE transition)
   * formaer rtc_init_entry() 
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onInitialize();

  /***
   *
   * The finalize action (on ALIVE->END transition)
   * formaer rtc_exiting_entry()
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onFinalize();

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

  /***
   *
   * The activated action (Active state entry action)
   * former rtc_active_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onActivated(RTC::UniqueId ec_id);

  /***
   *
   * The deactivated action (Active state exit action)
   * former rtc_active_exit()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id);

  /***
   *
   * The execution action that is invoked periodically
   * former rtc_active_do()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
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
  RTC::TimedString m_word;
  /*!
   */
  InPort<RTC::TimedString> m_wordIn;
  RTC::TimedFloat m_fontSize;
  /*!
   */
  InPort<RTC::TimedFloat> m_fontSizeIn;
  RTC::TimedString m_fontName;
  /*!
   */
  InPort<RTC::TimedString> m_fontNameIn;
  RTC::TimedShort m_wsCharacter;
  /*!
   */
  InPort<RTC::TimedShort> m_wsCharacterIn;
  RTC::TimedShort m_wsWord;
  /*!
   */
  InPort<RTC::TimedShort> m_wsWordIn;
  RTC::TimedShort m_wsLine;
  /*!
   */
  InPort<RTC::TimedShort> m_wsLineIn;
  RTC::TimedShort m_wsParagraph;
  /*!
   */
  InPort<RTC::TimedShort> m_wsParagraphIn;
  RTC::TimedShort m_wsWindow;
  /*!
   */
  InPort<RTC::TimedShort> m_wsWindowIn;
  RTC::TimedShort m_wsScreen;
  /*!
   */
  InPort<RTC::TimedShort> m_wsScreenIn;
  RTC::TimedRGBColour m_color;
  /*!
   */
  InPort<RTC::TimedRGBColour> m_colorIn;

  RTC::TimedBoolean m_MovementType;
  /*!
   */
  InPort<RTC::TimedBoolean> m_MovementTypeIn;

  RTC::TimedBoolean m_Italic;
  /*!
   */
  InPort<RTC::TimedBoolean> m_ItalicIn;

  RTC::TimedBoolean m_Bold;
  /*!
   */
  InPort<RTC::TimedBoolean> m_BoldIn;
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  RTC::TimedString m_selWord;
  /*!
   */
  OutPort<RTC::TimedString> m_selWordOut;
  RTC::TimedString m_copyWord;
  /*!
   */
  OutPort<RTC::TimedString> m_copyWordOut;
  
  // </rtc-template>

  // CORBA Port declaration
  // <rtc-template block="corbaport_declare">
  
  // </rtc-template>

  // Service declaration
  // <rtc-template block="service_declare">
  
  // </rtc-template>

  // Consumer declaration
  // <rtc-template block="consumer_declare">
  
  // </rtc-template>

  std::string file_path;
  float fontsize;
  std::string fontname;
  int Red;
  int Blue;
  int Green;
  int Italic;
  int Bold;


 private:
  // <rtc-template block="private_attribute">
  
  // </rtc-template>

  // <rtc-template block="private_operation">
  
  // </rtc-template>

};


extern "C"
{
  DLL_EXPORT void WordRTCInit(RTC::Manager* manager);
};

#endif // WORDRTC_H

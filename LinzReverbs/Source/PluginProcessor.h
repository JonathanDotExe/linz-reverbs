/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ProgramManager.h"
#include <memory>

//==============================================================================
/**
*/
class LinzReverbsAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    LinzReverbsAudioProcessor();
    ~LinzReverbsAudioProcessor() override;

    //==============================================================================
    // processing
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    // gui
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    // metadata
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    // presets
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    // state
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    //==============================================================================
    enum {
        oscIndex,
        convIndex,
        gainIndex
    };
    
    juce::Random random;
    juce::dsp::ProcessorChain<
        juce::dsp::Oscillator<float>,
        juce::dsp::Convolution,
        juce::dsp::Gain<float>> processorChain;
    
    std::unique_ptr<ProgramManager> progManager;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LinzReverbsAudioProcessor)
};

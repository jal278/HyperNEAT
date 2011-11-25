#ifndef __HCUBE_UserEvaluationFrame__
#define __HCUBE_UserEvaluationFrame__

#ifndef HCUBE_NOGUI

/**
@file
Subclass of GUITemplate, which is generated by wxFormBuilder.
@todo Add your event handlers directly to this file.
*/

#include "HCUBE_GUITemplate.h"

#include "HCUBE_Defines.h"

namespace HCUBE
{

    /** Implementing GUITemplate */
    class UserEvaluationFrame : public UserEvaluationFrameTemplate
    {
        DECLARE_EVENT_TABLE()
    public:
    protected:
        ExperimentRun *experimentRun;
        vector<wxToggleButton*> voteButtons;
        vector<EvaluationPanel*> evaluationPanels;

    public:
        /** Constructor */
        UserEvaluationFrame(
            ExperimentRun *_experimentRun,
            wxWindow* parent,
            int id = wxID_ANY,
            wxString title = wxT("User Evaluations"),
            wxPoint pos = wxDefaultPosition,
            wxSize size = wxSize( 800,600 ),
            int style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL
        );

        virtual ~UserEvaluationFrame()
        {}

        void updateIndividual(shared_ptr<NEAT::GeneticIndividual> individual);

        void updateEvaluationPanels();

        virtual void advanceGeneration( wxCommandEvent& event );

        virtual void resetVotes( wxCommandEvent& event );

        void handleMouseClick(wxMouseEvent& event);

        void processHighResImage(shared_ptr<NEAT::GeneticIndividual> individual);
    };

}

#endif

#endif // __HCUBE_UserEvaluationFrame__